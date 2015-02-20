#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float x;
  float y;
} point;

void squares(point pointArray[], int size) {
  int i;

  float sumX = 0;
  float sumX2 = 0;
  float sumY = 0;
  float sumXY = 0;

  float b1 = 0;
  float b0 = 0;

  for (i = 0; i < size; i++) {
    float x = pointArray[i].x;
    float y = pointArray[i].y;

    //printf("x: %f\ty: %f\n", x, y);

    sumX += x;
    sumX2 += x*x;
    sumY += y;
    sumXY += x*y;
  }

  b1 = (sumXY - ((sumX * sumY) / size)) / (sumX2 - (powf(sumX, 2) / size));
  b0 = (sumY - (b1 * sumX)) / size;

  printf("------------------------------------\n");
  printf("x: %f\ty: %f\tx^2: %f\txy: %f\n", sumX, sumY, sumX2, sumXY);
  printf("b0: %f\tb1: %f\n", b0, b1);
  printf("------------------------------------\n");
  printf("Final equation: y = %f + %fx\n", b0, b1);

  return;
}

int main (int argc, char *argv[]) {
  int lines = -1;
  int ch;
  float t, id, x, y, r;
  FILE *fp;
  char buffer1[20], buffer2[20], buffer3[20], buffer4[20], buffer5[20];

  if (argc != 2) {
    printf("Usage: least_squares in_file.txt\n");
    exit(1);
  }

  fp = fopen(argv[1], "r");

  if (fp == NULL) {
    exit(1);
  }

  while(!feof(fp)) {
    ch = fgetc(fp);
    if(ch == '\n') {
      lines++;
    }
  }
  printf("%d\n", lines);

  rewind(fp);

  point *pointArray;
  pointArray = malloc(lines*sizeof(point));

  int count = -1;

  while(count < lines) {
    if (count >= 0) {
      fscanf(fp, "%f %f %f %f %f\n", &t, &id, &x, &y, &r);
      pointArray[count].x = x;
      pointArray[count].y = y;
    } else {
      fscanf(fp, "%s %s %s %s %s\n", buffer1, buffer2, buffer3, buffer4, buffer5);
    }
    count++;
  }

  squares(pointArray, lines);

  free(pointArray);
  fclose(fp);

  exit(0);
}
