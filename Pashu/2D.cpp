#include <iostream.h> 
#include <graphics.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 
#include <math.h>
#include <dos.h>

int sq[4][2] = {
  {
    0,
    0
  },
  {
    100,
    0
  },
  {
    100,
    100
  },
  {
    0,
    100
  }
};
void put_line(int x1, int y1, int x2, int y2) {
  line(x1 + 320, 250 - y1, x2 + 320, 250 - y2);
}
void put_box(int sq[4][2]) {
  setcolor(RED);
  line(0, 250, 640, 250);
  setcolor(BLUE);
  line(320, 0, 320, 500);
  setcolor(WHITE);
  for (int i = 0; i < 3; i++) {
    put_line(sq[i][0], sq[i][1], sq[i + 1][0], sq[i + 1][1]);
  }
  put_line(sq[0][0], sq[0][1], sq[3][0], sq[3][1]);
}
void incr(int sq[4][2], int xincr, int yincr) {
  for (int i = 0; i < 4; i++) {
    sq[i][0] = sq[i][0] + xincr;
    sq[i][1] = sq[i][1] + yincr;
  }
}
void initia(int sq[4][2]) {
  
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  setcolor(RED);
  line(0, 250, 640, 250);
  setcolor(BLUE);
  line(320, 0, 320, 500);
  setcolor(WHITE);
  put_box(sq);
}
void rot(int sq[4][2], int sq2[4][2], int h, int k, float d) {
  for (int i = 0; i < 4; i++) {
    sq2[i][0] = (sq[i][0] - h) * cos(d) + (k - sq[i][1]) * sin(d) + h;
    sq2[i][1] = (sq[i][0] - h) * sin(d) + (sq[i][1] - k) * cos(d) + k;
  }
  put_box(sq2);
}
void rot_gen() {
  char key;
  int sq2[4][2];
  initia(sq);
  float d = 0;
  while ((key = getch()) != 'e') {
    if (((int) key) == 75) {
      d += 0.01;
      cleardevice();
      rot(sq, sq2, 0, 0, d);
    } else if (((int) key) == 77) {
      d -= 0.01;
      cleardevice();
      rot(sq, sq2, 0, 0, d);
    }
  }
  for (int i = 0; i < 4; i++) {
    sq[i][0] = sq2[i][0];
    sq[i][1] = sq2[i][1];
  }
  closegraph();
}
void rot_pt() {
  char key;
  int sq2[4][2];
  initia(sq);
  float d = 0;
  gotoxy(2, 2);
  cout << "Enter point about which rotation is to be done : (x,y) ";
  int rx, ry;
  cin >> rx >> ry;
  while ((key = getch()) != 'e') {
    if (((int) key) == 75) {
      d += 0.01;
      cleardevice();
      rot(sq, sq2, rx, ry, d);
    } else if (((int) key) == 77) {
      d -= 0.01;
      cleardevice();
      rot(sq, sq2, rx, ry, d);
    }
  }
  for (int i = 0; i < 4; i++) {
    sq[i][0] = sq2[i][0];
    sq[i][1] = sq2[i][1];
  }
  closegraph();
}
void translation() {
  initia(sq);
  int xincr, yincr;
  char key;
  while ((key = getch()) != 'e') {
    if (((int) key) == 72) {
      yincr = 5;
      xincr = 0;
      cleardevice();
      incr(sq, xincr, yincr);
      put_box(sq);
    } else if (((int) key) == 80) {
      yincr = -5;
      xincr = 0;
      cleardevice();
      incr(sq, xincr, yincr);
      put_box(sq);
    } else if (((int) key) == 75) {
      yincr = 0;
      xincr = -5;
      cleardevice();
      incr(sq, xincr, yincr);
      put_box(sq);
    } else if (((int) key) == 77) {
      yincr = 0;
      xincr = 5;
      cleardevice();
      incr(sq, xincr, yincr);
      put_box(sq);
    }
  }
  closegraph();
}
void sca(int sq[4][2], float scx, float scy, int h, int k) {
  for (int i = 0; i < 4; i++) {
    sq[i][0] = sq[i][0] * scx - (scx * h) + h;
    sq[i][1] = sq[i][1] * scy - (scy * k) + k;
  }
  put_box(sq);
}
void scale_fix() {
  char key;
  int sq2[4][2];
  initia(sq);
  float scx, scy;
  gotoxy(2, 2);
  cout << "Enter fixed point : ";
  int sx, sy;
  gotoxy(3, 2);
  cin >> sx >> sy;
  while ((key = getch()) != 'e') {
    if (((int) key) == 72) {
      scy = 1.1;
      scx = 1.0;
      cleardevice();
      sca(sq, scx, scy, sx, sy);
    } else if (((int) key) == 80) {
      scy = 1.0 / 1.1;
      scx = 1.0;
      cleardevice();
      sca(sq, scx, scy, sx, sy);
    } else if (((int) key) == 75) {
      scx = 1.0 / 1.1;
      scy = 1.0;
      cleardevice();
      sca(sq, scx, scy, sx, sy);
    } else if (((int) key) == 77) {
      scx = 1.1;
      scy = 1.0;
      cleardevice();
      sca(sq, scx, scy, sx, sy);
    }
  }
  closegraph();
}
void scale_gen() {
  char key;
  int sq2[4][2];
  initia(sq);
  float scx, scy;
  while ((key = getch()) != 'e') {
    if (((int) key) == 72) {
      scy = 1.1;
      scx = 1.0;
      cleardevice();
      sca(sq, scx, scy, 0, 0);
    } else if (((int) key) == 80) {
      scy = 1.0 / 1.1;
      scx = 1.0;
      cleardevice();
      sca(sq, scx, scy, 0, 0);
    } else if (((int) key) == 75) {
      scx = 1.0 / 1.1;
      scy = 1.0;
      cleardevice();
      sca(sq, scx, scy, 0, 0);
    } else if (((int) key) == 77) {
      scx = 1.1;
      scy = 1.0;
      cleardevice();
      sca(sq, scx, scy, 0, 0);
    }
  }
  closegraph();
}
void main() {
  clrscr();
  int ch;
  do {
    cout << "\t 2D Transformation";
    cout << "\n\n 1. Rotation about origin \n 2. Rotation about any point \n 3. Translation\n 4. Scaling with no fixed point\n 5. Scaling with fixed point\n 6. Exit";
    cout << "\n\n Enter Choice : ";
    cin >> ch;
    switch (ch) {
    case 1:
      rot_gen();
      break;
    case 2:
      rot_pt();
      break;
    case 3:
      translation();
      break;
    case 4:
      scale_gen();
      break;
    case 5:
      scale_fix();
      break;
    case 6:
      break;
    default:
      cout << "invalid choice ";
    }
  }
  while (ch != 6);
}