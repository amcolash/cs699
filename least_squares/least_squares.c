#include <math.h>
#include <stdio.h>

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

int main () {
  int size = 8;
  point pointArray[size];

  pointArray[0].x = 65;
  pointArray[1].x = 65;
  pointArray[2].x = 62;
  pointArray[3].x = 67;
  pointArray[4].x = 69;
  pointArray[5].x = 65;
  pointArray[6].x = 61;
  pointArray[7].x = 67;

  pointArray[0].y = 105;
  pointArray[1].y = 125;
  pointArray[2].y = 110;
  pointArray[3].y = 120;
  pointArray[4].y = 140;
  pointArray[5].y = 135;
  pointArray[6].y = 95;
  pointArray[7].y = 130;

/*
  int i;
  int size = 100;

  for (i = 0; i < size; i++) {
    pointArray[i].x = i;
    pointArray[i].y = i;
  }
*/

  squares(pointArray, size);

  return 0;
}
