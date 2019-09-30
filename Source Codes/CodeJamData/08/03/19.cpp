#include <iostream>
#include <string> 
#include <cassert>
#include <algorithm> 
#include <cmath>
#define NDEBUG
#ifdef NDEBUG
#define DBG(x) 
#else
#define DBG(x) x
#endif

using namespace std;

bool hitbylines(double x, double y, double r, double f, double g){
  double kx = round(x/(2*r+g));
  double errx = x - kx*(2*r+g);
  double ky = round(y/(2*r+g));
  double erry = y - ky*(2*r+g);
  return abs(errx) < r+f || abs(erry) < r+f;
}

bool hitbyedge(double x, double y, double R, double f, double t){
  return x*x + y*y > (R-f-t)*(R-f-t);
}

/*
double randangl(){
  return ((double)rand()/((double)RAND_MAX + 1.0))*2*3.141592653589;
}

double randrds(){
  return sqrt(((double)rand()/((double)RAND_MAX + 1.0)));
}
*/

// works for upper right quadrant.
// rtf = R - t - f = radius of inner boundary 
double computeArea(double llx, double lly, double rrx, double rry, double rtf, double maxarea){
  //cout << "computing " << llx << " " << lly << endl;
  const double threshold = 1E-12*maxarea;
  if(llx >= rrx || lly >= rry) return 0;
  double area = (rrx-llx)*(rry-lly);
  if(area < threshold) return area/2;
  if(rrx*rrx + rry*rry <  rtf*rtf){
    return area;
  }
  if(llx*llx + lly*lly >= rtf*rtf){
    return 0;
  }
  double cx = (llx+rrx)/2, cy = (lly+rry)/2; // center point
  return computeArea(llx,lly,cx,cy,rtf,maxarea) // lower-left corner
    + computeArea(cx,cy,rrx,rry,rtf,maxarea) // upper right corner
    + computeArea(llx,cy,cx,rry,rtf,maxarea) // upper left corner
    + computeArea(cx,lly,rrx,cy,rtf,maxarea); // lower right corner
}

void readandsolve(int cse){
  double f,R,t,r,g;
  cin >> f >> R >> t >> r >> g;
  double maxarea = 3.141592653589*R*R/4;
  double complement = 0;
  for(int x=0; (2*x+1)*(g/2+r)-g/2+f < R-t-f; ++x){
    for(int y=0; y < x; ++y){
      complement += 
	2*computeArea((2*x+1)*(g/2+r)-g/2+f,
		    (2*y+1)*(g/2+r)-g/2+f,
		    (2*x+1)*(g/2+r)+g/2-f,
		    (2*y+1)*(g/2+r)+g/2-f,
		      R-t-f,maxarea);
    }
    complement += 
      computeArea ((2*x+1)*(g/2+r)-g/2+f,
		   (2*x+1)*(g/2+r)-g/2+f,
		   (2*x+1)*(g/2+r)+g/2-f,
		   (2*x+1)*(g/2+r)+g/2-f,
		   R-t-f,maxarea); 
  }

  double ans = complement/(maxarea);
  printf("Case #%d: %.6f\n", cse, 1-ans);
}

int main(){

  int n;
  cin >> n;
  for (int i=0; i<n; ++i){
    readandsolve(i+1);
  }
  return 0; 
}
