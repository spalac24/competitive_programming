#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define D(x) cout<<(#x)<<" is = "<<(x)<<endl

using namespace std;

const double EPS = 1e-9;

void line_line_intersection(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, double &x, double &y) {
    double t0 = (y3-y2)*(x0-x2) - (x3-x2)*(y0-y2);
    double t1 = (x1-x0)*(y2-y0)-(y1-y0)*(x2-x0);
    double det = (y1-y0)*(x3-x2)-(y3-y2)*(x1-x0);
  //  D(det);
    t0 /= det;
    t1 /= det;
    x = x0+t0*(x1-x0);
    y = y0+t0*(y1-y0);
 //   puts("line");D(x0);D(y0);D(x1);D(y1);D(x2);D(y2);D(x3);D(y3);D(x);D(y);
}

void half (double x0,double y0, double x1, double y1, double &x, double &y) {
    x = (x0+x1)/2.0;
    y = (y0+y1)/2.0;
   // puts("half");D(x0);D(y0);D(x1);D(y1);D(x);D(y);
}

double area (double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3){

    double ret = ((x0*y1-x1*y0)+(x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y0-x0*y3))/(160.0*2.0);

  // puts("area");D(x0);D(y0);D(x1);D(y1);D(x2);D(y2);D(x3);D(y3);D(ret);
    return ret;
}

double dist (double x0, double y0, double x1, double y1) {
    double x = x0-x1;
    double y = y0-y1;
    double ret = (x*x+y*y);

  //  puts("dist"); D(x); D(y); D(x*x); D(y*y);D(x0);D(y0);D(x1);D(y1);D(ret);
    return sqrt(ret);
}

int main () {
    double ax,ay,bx,by,cx,cy,dx,dy;
    int n;
    cin>>n;
    while(n--) {
        int m;
        cin>>m;
        cout<<m;
        ax = ay = by = 0.0;
        cin>>bx>>cx>>cy>>dx>>dy;
        double p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y;
        double apx,apy,bpx,bpy,cpx,cpy,dpx,dpy;
        half(bx,by,cx,cy,apx,apy);
        half(cx,cy,dx,dy,bpx,bpy);
        half(dx,dy,ax,ay,cpx,cpy);
        half(ax,ay,bx,by,dpx,dpy);
        line_line_intersection(dx,dy,dpx,dpy,ax,ay,apx,apy,p1x,p1y);
        line_line_intersection(ax,ay,apx,apy,bx,by,bpx,bpy,p2x,p2y);
        line_line_intersection(bx,by,bpx,bpy,cx,cy,cpx,cpy,p3x,p3y);
        line_line_intersection(cx,cy,cpx,cpy,dx,dy,dpx,dpy,p4x,p4y);
        //D(p1x); D(p1y);D(p2x);D(p2y);D(p3x);D(p3y);D(p4x);D(p4y);
        double a1,a2,a3,a4,a5;
        a1 = area(ax,ay,bx,by,p2x,p2y,p1x,p1y);
        a2 = area(bx,by,cx,cy,p3x,p3y,p2x,p2y);
        a3 = area(cx,cy,dx,dy,p4x,p4y,p3x,p3y);
        a4 = area(dx,dy,ax,ay,p1x,p1y,p4x,p4y);
        a5 = area(p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y);
       // D(a1);D(a2);D(a3);D(a4);D(a5);
        double per = dist(p1x,p1y,p2x,p2y);
        per += dist(p2x,p2y,p3x,p3y);
        per += dist(p3x,p3y,p4x,p4y);
        per += dist(p4x,p4y,p1x,p1y);
       printf(" %.3lf %.3lf %.3lf %.3lf %.3lf %d\n%",a1,a2,a3,a4,a5,(int)ceil(per*16.5+EPS));
    }
}
