#include <iostream.h> 
#include <graphics.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <dos.h>

int main(void) {
  int gd = DETECT, gm;
  float t, i, y, x, j, k;
  int cx[20], cy[20], n;

  /* initialize graphics and local
  variables */

  initgraph( & gd, & gm, "C:\\TURBOC3\\BGI");
  line(320, 0, 320, 480);
  line(0, 240, 640, 240);
  cout << "enter the no of pts";
  cin >> n;
  for (i = 1; i < n - 1; i++) {
    cout << "enter the control pts ";
    cin >> cx[i] >> cy[i];
  }
  cout << "enter the start and end point x,y c ordinates";
  cin >> cx[0] >> cy[0] >> cx[n - 1] >> cy[n - 1];
  for (i = 3; i <= n - 1; i++) {
    for (t = 0; t <= 1; t += .0005) {
      x = ((pow((1 - t), 3)) * cx[i - 3] + (3 * t * t * t - 6 * t * t + 4) * cx[i - 2] + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * cx[i - 1] + t * t * t * cx[i]) / 6;
      y = ((pow((1 - t), 3)) * cy[i - 3] + (3 * t * t * t - 6 * t * t + 4) * cy[i - 2] + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * cy[i - 1] + t * t * t * cy[i]) / 6;
      putpixel(320 + x, 240 - y, RED);
      delay(1);
    }
  }
  putpixel(320 + cx[0], 240 - cy[0], WHITE);
  putpixel(320 + cx[n - 1], 240 - cy[n - 1], WHITE);
  getch();
}