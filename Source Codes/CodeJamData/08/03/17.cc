#include <iostream>
#include <cmath>
#include <complex>
using namespace std;
typedef complex<double> XY;
double PI = atan(1.0) * 4.0;
double integral(double x1, double x2, double r){
  double theta1 = asin(x1/r);
  double theta2 = asin(x2/r);
  if(theta1 > PI/2.0){
    theta1 = PI-theta1;
  }
  if(theta2 > PI/2.0){
    theta2 = PI-theta2;
  }
  //cout << x1 << " x1 x2 " << x2 << endl;
  //cout << theta1 << " t1 t2 " << theta2 << endl;
  return r*r*((sin(2.0*theta2)/4.0+0.5*theta2)-(sin(2.0*theta1)/4.0+0.5*theta1));
}

int main(){
  int cases;
  cin >> cases;
  int temp = 0;
  while(cases--){
    double f,R,t,r,g;
    cin >> f >> R >> t >> r >> g;
    cout << "Case #" << ++temp << ": ";
    double all = R*R*PI/4.0;
    double ret = 0.0;
    double radii = R-t-f;
    for(double y=r;y<R-t;y+=2*r+g){
      for(double x=r;x<R-t;x+=2*r+g){
	if(radii <= 0.0)continue;
	double left = x+f;
	double bottom = y+f;
	double top = y+g-f;
	double right = x+g-f;
	if(right <= left || top <= bottom)continue;
	if(radii<=abs(XY(left,bottom)))continue;
	if(abs(XY(right,top))<=radii){
	  ret += (top-bottom)*(right-left);
	  continue;
	}
	double cxb = -1.0;
	double cxt = -1.0;
	if(radii>=bottom){
	  cxb = sqrt(radii*radii-bottom*bottom);
	  if(left <= cxb && cxb <= right){
	  } else {
	    cxb = -1.0;
	  }
	} else {
	  continue;
	}
	if(radii>=top){
	  cxt = sqrt(radii*radii-top*top);
	  if(left <= cxt && cxt <= right){
	  } else {
	    cxt = -1.0;
	  }
	}
	
	if(cxb != -1.0 && cxt != -1.0){
	  ret += (cxt-left)*(top-bottom);
	  ret += integral(cxt, cxb, radii) - (cxb-cxt)*bottom;
	} else if(cxb == -1.0 && cxt != -1.0){
	  ret += (cxt-left)*(top-bottom);
	  ret += integral(cxt, right, radii) - (right-cxt)*bottom;
	} else if(cxb != -1.0 && cxt == -1.0){
	  //  cout << "radii:" << radii << " " << "integral:" << integral(left, cxb, radii) << endl;
	  ret += integral(left, cxb, radii) - (cxb-left)*bottom;
	} else {
	  ret += integral(left, right, radii) - (right-left)*bottom;
	}
      }
    }
    printf("%.10f\n", 1.0-ret/all);
  }
  return 0;
}
