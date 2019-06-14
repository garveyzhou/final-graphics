#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mesh.h"
#include "matrix.h"
#include "draw.h"

char * parse(char *line) {
  char * s = calloc (sizeof(char), 1);
  strcpy(s, strsep(&line, " "));
  return s;
}

char ** parse_args(char *line){
  char ** arr = calloc(sizeof(char*), 10);
  int i = 0;
  while (line) {
    arr[i] = strsep(&line, " ");
    if (strlen(arr[i]) != 0) {
      arr[i] = parse(arr[i]);
      i++;
    }
  }
  return arr;
}

void parse_file(struct matrix * polygons, char * file){
  FILE *f;
  char line[255];
  double values[4];
  struct matrix * vertices = new_matrix(3,100);
  struct matrix * faces = new_matrix(4,100);
  f = fopen(file,"r");
  while ( fgets(line, sizeof(line), f) != NULL ) {
    line[strlen(line) - 1] = '\0';
    if (strncmp(line, "v", 1) == 0) {
      sscanf(line, "%s %lf %lf %lf", type, values, values+1, values+2);
      if (strncmp(type, "v", strlen(type)) == 0) {
        add_point(vertices,values[0],values[1],values[2]);
        vertices->m[3][vertices->lastcol] = 0;
      }
    }

    else if (strncmp(line, "f", 1) == 0) {
      args = parse_args(line);
      int i = 0;
      while (args[i+1] && (i < 4)) {
        values[i] = atof(args[i+1]);
        i++;
      }
      add_point(faces,values[0],values[1],vales[2]);
      faces->m[3][faces->lastcol] = values[3];
    }
  }



}
