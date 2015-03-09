#ifndef GSCIE_ARRAY_H_
#define GSCIE_ARRAY_H_

#include <glib-object.h>
#include <gio/gio.h>
#include <omp.h>

#define GSCIE_TYPE_ARRAY (gscie_array_get_type ())
#define GSCIE_ARRAY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GSCIE_TYPE_ARRAY, GscieArray))
#define GSCIE_IS_ARRAY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GSCIE_TYPE_ARRAY))
#define GSCIE_ARRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GSCIE_TYPE_ARRAY, GscieArrayClass))
#define GSCIE_IS_ARRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GSCIE_TYPE_ARRAY))
#define GSCIE_ARRAY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GSCIE_TYPE_ARRAY, GscieArrayClass))

typedef struct _GscieArray GscieArray;
typedef struct _GscieArrayClass GscieArrayClass;
typedef struct _GscieArrayPrivate GscieArrayPrivate;
struct _GscieArray // to edit
{
	/* Parent instance structure */
	GObject parent_instance;
	/* private member */
	GscieArrayPrivate *priv;
	/* instance members */
};
struct _GscieArrayClass
{
	/* Parent class structure */
	GObjectClass parent_class;
	/* class members */
};

/* used by MAMAN_TYPE_BAR */
GType gscie_array_get_type(void);
//GscieArray * gscie_array_new(void);

//GscieArray *gscie_array_new_length(const guint l);

guint gscie_array_get_length(GscieArray *self);

#endif /* GSCIE_ARRAY_H_ */
