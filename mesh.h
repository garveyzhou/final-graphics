#ifndef MESH_H
#define MESH_H

#include "mesh.h"
#include "matrix.h"
#include "draw.h"

void parse_file(struct matrix *polygons, char *file);
void add_mesh(struct matrix *polygons, struct matrix *vertices, struct matrix *faces);

#endif
