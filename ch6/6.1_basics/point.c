#include <stdio.h>
#define XMAX 320
#define YMAX 200
struct point{
  int x;
  int y;
};

struct rect{ // 约定pt1是左下角的点 pt2是右上角的点
  struct point pt1;
  struct point pt2;
};

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);
int ptinrect(struct point p, struct rect r);


#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


int main()
{
  struct point pt;
  struct point maxpt = {320, 200};

  printf("x=%d, y=%d\n", pt.x, pt.y);

  struct rect screen;
  screen.pt1.x = 20;
  screen.pt1.y = 20;
  // screen.pt2 = {58, 50}; // error


  struct point middle;
  struct point makepoint(int, int);
  screen.pt1 = makepoint(0,0);
  screen.pt2 = makepoint(XMAX, YMAX);
  middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                     (screen.pt1.y + screen.pt2.y)/2);

  struct point *pp;
  pp = &middle;
  printf("middle is (%d,%d)\n", (*pp).x, (*pp).y);
  return 0;
}

struct point makepoint(int x, int y)
{
  struct point p;
  p.x = x;
  p.y = y;
  return p;
}

// 结构类型的参数和int一样 是值传递的
struct point addpoint(struct point p1, struct point p2)
{
  p1.x+=p2.x;
  p1.y+=p2.y;
  return p1;
}

int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x
    && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
  struct rect temp;
  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);
  return temp;
}
