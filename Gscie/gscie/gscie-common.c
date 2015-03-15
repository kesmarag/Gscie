#include "gscie-common.h"

gint _gscie_array_length(gpointer array){
	gint length = 0;
	if (array){
		while (((gpointer*) array)[length]) {
					length++;
				}
		return length;
	}else return -1;
}


gdouble _gscie_double_parse (const gchar *str){
	gdouble result = 0.0;
	g_return_val_if_fail (str != NULL, 0.0);
	result = g_ascii_strtod (str, NULL);
	return result;
}
