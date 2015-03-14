#ifndef GSCIE_H_
#define GSCIE_H_
#include <glib-object.h>
#include "gscie-array.h"

void gscie_read_vector_from_file(GscieArray *vec, \
		const gchar *filename, const gchar mode, const guint i);

#endif /* GSCIE_H_ */
