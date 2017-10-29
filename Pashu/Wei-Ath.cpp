#include <iostream.h> 
#include <graphics.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <dos.h>

float sdx[15], sdy[15];
int i, w = 0, h;
void sort(float sdy[], int h) {
  float temp;
  for (int j = 0; j <= h - 1; j++) {
    for (i = 0; i < h - 1 - j; i++) {
      if (sdy[i] > sdy[i + 1]) {
        temp = sdy[i];
        sdy[i] = sdy[i + 1];
        sdy[i + 1] = temp;
      }
    }
  }
}

struct ather {
  float x;
  float y;
  float io;
  float vis;
};
struct ather z[20];
void main() {
  
  clrscr();
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  int n, m, s;
  float px[15] = {
    0
  };
  float py[15] = {
    0
  };
  float pdx[15], pdy[10];
  float outx[15] = {
    0
  };
  float outy[15] = {
    0
  };
  
  float xmin, ymin, xmax, ymax;
  printf("enter xmin,ymin,xmax,ymax");
  scanf("%f%f%f%f", & xmin, & ymin, & xmax, & ymax);
  rectangle(320 + xmin, 240 - ymax, 320 + xmax, 240 - ymin);
  printf("enter the no. of vertices (n)");
  scanf("%d", & n);
  printf("enter the x coordinate of all vertices");
  
  for (m = 0; m < n; m++) {
    scanf("%f", & px[m]);
  }
  printf("enter the y coordinate of all vertices");
  for (m = 0; m < n; m++) {
    scanf("%f", & py[m]);
  }
  rectangle(320 + xmin, 240 - ymax, 320 + xmax, 240 - ymin);
  px[n] = px[0];
  py[n] = py[0];
  for (s = 0; s < n; s++) {
    line(320 + px[s], 240 - py[s], 320 + px[s + 1], 240 - py[s + 1]);
  }
  getch();
  px[n] = px[0];
  py[n] = py[0];
  int l = 0;
  for (m = 0; m < n; m++) {
    if (px[m] >= xmin && px[m + 1] <= xmin) {
      pdx[m] = xmin;
      pdy[m] = py[m] + ((py[m + 1] - py[m]) / (px[m + 1] - px[m])) * (xmin - px[m]);
      outx[l] = pdx[m];
      outy[l] = pdy[m];
      z[l].io = 1;
      l++;
    }
    if (px[m] >= xmin && px[m + 1] >= xmin) {
      outx[l] = px[m + 1];
      outy[l] = py[m + 1];
      z[l].io = 0;
      l++;
    }
    if (px[m] <= xmin && px[m + 1] >= xmin) {
      pdx[m] = xmin;
      pdy[m] = py[m] + ((py[m + 1] - py[m]) / (px[m + 1] - px[m])) * (xmin - px[m]);
      outx[l] = pdx[m];
      outy[l] = pdy[m];
      z[l].io = 0;
      l++;
      outx[l] = px[m + 1];
      outy[l] = py[m + 1];
      z[l].io = 0;
      l++;
    }
  }
  outx[l] = outx[0];
  outy[l] = outy[0];
  setcolor(GREEN);
  for (i = 0; i < l; i++) {
    if (outx[i] == xmin) {
      sdx[w] = outx[i];
      sdy[w] = outy[i];
      w++;
    }
  }
  sort(sdy, w);
  outx[l] = outx[0];
  outy[l] = outy[0];
  for (i = 0; i <= l; i++) {
    z[i].x = outx[i];
    z[i].y = outy[i];
    z[i].vis = 0;
  }
  s = 0;
  for (m = 0; m <= l - 1; m++) {
    outx[l] = outx[0];
    outy[l] = outy[0];
    sdx[w + 1] = sdx[0];
    sdy[w + 1] = sdy[0];
    if (z[s].io == 0) {
      line(320 + outx[s], 240 - outy[s], 320 + outx[s + 1], 240 - outy[s + 1]);
      z[s].vis = 1;
      z[s + l].vis = 1;
    } else if (z[s].io == 1) {
      for (i = 0; i <= w; i++) {
        if (sdy[i] == outy[s]) {
          line(320 + sdx[i], 240 - sdy[i], 320 + sdx[i + 1], 240 - sdy[i + 1]);
          z[s].vis = 1;
          z[s + l].vis = 1;
          break;
        }
      }
      for (int j = 0; j < l; j++) {
        if (sdy[i + 1] == z[j].y) {
          s = j;
          line(320 + outx[s], 240 - outy[s], 320 + outx[s + 1], 240 - outy[s + 1]);
          z[s].vis = 1;
          z[s + l].vis = 1;
          break;
        }
      }
    }
    if (s <= l - 1) {
      s++;
    } else {
      s = 0;
    }
    if (s == l) {
      s = 0;
    }
    int p = s;
    while (z[s].vis == 1) {
      s++;
      if (s == p + l) {
        break;
      }
    }
  }
  getch();
}