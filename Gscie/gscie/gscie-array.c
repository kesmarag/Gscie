#include "gscie-array.h"

enum {
	PROP_0,

	PROP_LENGTH,
	PROP_FILENAME,

	N_PROPERTIES
};

static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };

struct _GscieArrayPrivate {
	gdouble *data;
	guint length;
	gchar *filename;
};

static void gscie_array_set_property(GObject *object,
									guint property_id,
									const GValue *value,
									GParamSpec *pspec)
{

	GscieArray *self = GSCIE_ARRAY(object);

	switch (property_id){
	case PROP_LENGTH:
		self->priv->length = g_value_get_uint(value);
		break;
	case PROP_FILENAME:
		g_free (self->priv->filename);
		self->priv->filename = g_value_dup_string (value);
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void gscie_array_get_property(GObject *object,
									guint property_id,
									GValue *value,
									GParamSpec *pspec)
{
	GscieArray *self = GSCIE_ARRAY(object);

	switch (property_id){
	case PROP_LENGTH:
		g_value_set_uint(value,self->priv->length);
		break;
	case PROP_FILENAME:
		g_value_set_string(value,self->priv->filename);
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}

}

G_DEFINE_TYPE_WITH_PRIVATE (GscieArray, gscie_array, G_TYPE_OBJECT)

static void gscie_array_finalize (GObject *gobject){
	GscieArray * self = GSCIE_ARRAY(gobject);
	g_free(self->priv->data);
	G_OBJECT_CLASS (gscie_array_parent_class)->finalize(gobject);
	g_print ("hello from gscie_array_finalize\n");
}

static void gscie_array_class_init (GscieArrayClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

	gobject_class->set_property = gscie_array_set_property;
	gobject_class->get_property = gscie_array_get_property;
	gobject_class->finalize = gscie_array_finalize;
	obj_properties[PROP_LENGTH] =
	g_param_spec_uint("length",
					"vector length property",
					"set the vector length",
					0,
					100000,
					0,
					G_PARAM_CONSTRUCT_ONLY |
					G_PARAM_READWRITE |
					G_PARAM_PRIVATE
					);
	obj_properties[PROP_FILENAME] =
	g_param_spec_string("file",
					"filename property",
					"define data filename",
					"gscie-vector.txt",
					G_PARAM_CONSTRUCT_ONLY |
					G_PARAM_WRITABLE |
					G_PARAM_PRIVATE
					);
	g_object_class_install_properties (gobject_class,
					N_PROPERTIES,
					obj_properties);
}

static void gscie_array_init(GscieArray *self) {
	self->priv = gscie_array_get_instance_private(self);
	g_print("hello from gscie_array_init!\n");
	self->priv->data = (gdouble *) g_malloc0(self->priv->length*sizeof(gdouble));
}


guint gscie_array_get_length(GscieArray *self){
	guint length;
	g_object_get(self,"length",&length,NULL);
	int i;
	double sum = 0;
	#pragma omp parallel for reduction (+:sum)
	for(i=1;i<100;i=i+1){
		sum +=(double)i*(double)i;}
	g_print("sum = %f\n",sum);

	GFile * test_file = g_file_new_for_path("/home/kesmarag/hello.txt");
	gboolean Bool = FALSE;
	Bool = g_file_query_exists(test_file,NULL);
	if (Bool == FALSE) g_print ("file doesn't exist!\n");
	GInputStream * dis ;
	dis = g_file_read (test_file, NULL, NULL);
	GDataInputStream * dis_new =  g_data_input_stream_new ((GInputStream*) dis);
	gchar * line = NULL;
	line = g_data_input_stream_read_line (dis_new, NULL, NULL, NULL);
	g_print ("%s\n",line);
	return length;

}


void gscie_array_add(GscieArray *self,gdouble node){
	self->priv = gscie_array_get_instance_private(self);
	self->priv->length++;
	self->priv->data = g_renew(gdouble,self->priv->data,self->priv->length);
	(self->priv->data)[self->priv->length-1] = node;
}

void gscie_array_print(GscieArray *self){
	self->priv = gscie_array_get_instance_private(self);
	gint i;
	for (i=0;i<self->priv->length;i++) g_print("%f\n",self->priv->data[i]);
}
