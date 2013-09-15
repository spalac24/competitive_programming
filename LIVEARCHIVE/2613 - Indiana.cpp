#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long double Double;

const Double EPS = 1e-9;
int cmp(Double x, Double y = 0, Double tol = EPS){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct Point {
  Double x;
  Double y;
  Double z;
  Point () {}
  Point (Double a, Double b, Double c=0.0): x(a), y(b), z(c) {}
  Point operator + (const Point &p) const {
    return Point(x + p.x, y + p.y, z + p.z);
  }
  Point operator - (const Point &p) const {
    return Point (x-p.x, y-p.y);   
  }
  Double length () const {
    return sqrtl((*this) * (*this)); 
  }
  // Dot product
  Double operator * (const Point &p) const {
    return x*p.x + y*p.y + z*p.z;
  }
  // Cross product
  Point operator ^ (const Point &v) const {
    return Point(y*v.z - v.y*z, -x*v.z + v.x*z, x*v.y - v.x*y);
  }
  void normalize() {
    Double d = length();
    x /= d; y /= d; z /= d;
  }
  operator string () const {
    stringstream ss;
    ss << "(";
    ss << x;
    ss<<" , ";
    ss<< y;
    ss << ")";
    return ss.str();
  }
};

Point operator * (Double t, const Point &p) {
  return Point(t * p.x, t * p.y, t * p.z);
}

Double distance_point_to_segment(const Point &p, const Point &a,
				 const Point &b) {
  if ((b-a).length() < EPS) {
    return (p-a).length();
  }
  Point u = b - a;
  Point v = p - a;
  Double t = (u * v) / (u * u);
  if (t < 0.0) t = 0.0;
  if (t > 1.0) t = 1.0;
  // Actual closest point is a + t*(b - a).
  Point boom = a + t*u;
  return (boom - p).length();
}

Double distance_between_segments(const Point &a1, const Point &b1, const Point &a2, const Point &b2){
  if ((a1-b1).length()<EPS) {
    return distance_point_to_segment(a1,a2,b2);
  }
  //    cout<<"from "<<string(a1)<<" -- "<<string(b1)<<"  to  "<<string(a2)<<" -- "<<string(b2)<<endl;
  Point u = b1 - a1;
  Point v = b2 - a2;
  Point w = a1 - a2;
  Double a = u * u;
  Double b = u * v;
  Double c = v * v;
  Double d = u * w;

  Double e = v * w;
  Double den = a*c - b*b;
  Double t1, t2;
  if (cmp(den, 0.0) == 0) { // the lines are parallel
    t1 = 0;
    t2 = d / b;
  } else {
    t1 = (b * e - c * d) / den;
    t2 = (a * e - b * d) / den;
  }
  // The shortest distance between the two infinite lines happens
  // from:
  // - On segment 1: p = a1 + t1 * (b1 - a1)
  // - On segment 2: q = a2 + t2 * (b2 - a2)
  if (0 <= t1 and t1 <= 1 and 0 <= t2 and t2 <= 1) {
    // We were lucky, the closest distance between the two
    // infinite lines happens right inside both segments.
    Point p = a1 + t1 * u;
    Point q = a2 + t2 * v;
    return (p - q).length();
  } else {
    Double ans = distance_point_to_segment(a2, a1, b1);
    ans = min(ans, distance_point_to_segment(b2, a1, b1));
    ans = min(ans, distance_point_to_segment(a1, a2, b2));
    ans = min(ans, distance_point_to_segment(b1, a2, b2));
    return ans;
  }
}

int n;
const int MAXN = 1000;

Point pi [MAXN+5];
Point pf [MAXN+5];

Double segment_segment (int i, int j) {
  return distance_between_segments(pi[i],pf[i],pi[j],pf[j]);
}

struct edge {
  int to;
  Double weight;
  edge(){}
  edge(int t, Double w) {
    to = t;
    weight = w;
           
  }  
  bool operator < (const edge &that) const {
    return weight > that.weight;   
  }
};

vector<edge> g [MAXN+5];

Double d [MAXN+5];
int p [MAXN+5];

Double dijkstra (int s, int t) {
  for (int i = 0; i < n; ++i) {
    d[i] = INFINITY;
    p[i] = -1;   
  }
  d[s] = 0.0;
  priority_queue<edge> q;
  q.push(edge(s,0));
  while(!q.empty()) {
    int node = q.top().to;
    Double dist = q.top().weight;
    q.pop();
    if (dist > d[node]) continue;
            
    if (node == t) {
      return dist;   
    }    
    for (int i = 0; i < g[node].size(); ++i) {
      int to = g[node][i].to;
      Double w_extra = g[node][i].weight;
      //assert(cmp(w_extra,segment_segment(node,to)) == 0);
      if (max(dist,w_extra) < d[to]) {
	d[to] = max(dist,w_extra);
	p[to] = node;
	q.push(edge(to,d[to]));   
      }
    }
  }
  assert(false);
  return 1e100;
  
}

int main () {
  //freopen("in.txt","r",stdin);
  while(cin>>n) {
    if (n == 0) break;
    int l;
    for (int i = 0; i < n; ++i) {
      cin>>pi[i].x>>pi[i].y>>l;
      if (l >= 0) {
	pf[i].x = pi[i].x + l;
	pf[i].y = pi[i].y; 
      }
      else {
	pf[i].x = pi[i].x;
	pf[i].y = pi[i].y-l;   
      }
    }
    for (int i = 0; i < n; ++i) {
      g[i].clear();
      g[i].reserve(n);
      for (int j = 0; j < n; ++j) {
	if (i == j) continue;
	g[i].push_back(edge(j,segment_segment(i,j)));
                
      }   
    }
    dijkstra(0,1);
    assert(p[1] != -1);
    cout << fixed<<setprecision(2)<< d[1]<<endl;
  }
}
