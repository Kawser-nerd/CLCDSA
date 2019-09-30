#include <iostream>
#include <iomanip>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

const double PI = atan(1.0)*4;

double calc(double r, double x1, double x2)
{
	double t1 = asin(x1 / r);
	double t2 = asin(x2 / r);
	return r*r/2 * ((t2 + sin(2*t2)/2) - (t1 + sin(2*t1)/2));
}

double solve(double f, double R, double t, double r, double g)
{
	double totalArea = R*R*PI;
	double nonhitArea = 0.0;

	double w = g/2 - f;
	double Rtf = R-t-f;
	if( w > 0 && Rtf > 0 )
	{
		for(int kx=0 ;; ++kx)
			for(int ky=0 ;; ++ky)
			{
				double cx = (r+g/2)+(g+2*r)*kx;
				double cy = (r+g/2)+(g+2*r)*ky;
				// square (cx-w,cy-w)--(cx+w,cy+w)  intersects circle (0,0)@Rtf

				if( abs(complex<double>(cx+w,cy+w)) <= Rtf )
					nonhitArea += w*w*4;
				else if( abs(complex<double>(cx-w,cy-w)) >= Rtf )
					{ if(ky==0)goto breakx; else break; }
				else
				{
					double bottom_x = sqrt((Rtf)*(Rtf) - (cy-w)*(cy-w));
					double left_y   = sqrt((Rtf)*(Rtf) - (cx-w)*(cx-w));
					double top_x, right_y;
					if( (Rtf)*(Rtf) >= (cy+w)*(cy+w) )
						top_x = sqrt((Rtf)*(Rtf) - (cy+w)*(cy+w));
					if( (Rtf)*(Rtf) >= (cx+w)*(cx+w) )
						right_y = sqrt((Rtf)*(Rtf) - (cx+w)*(cx+w));
					double diff = 0;
					if( bottom_x < cx+w )
						if( left_y < cy+w ) // 1
						{
							diff = calc(Rtf, cx-w, bottom_x) - (bottom_x-(cx-w))*(cy-w);
						}
						else // 2
						{
							diff = calc(Rtf, top_x, bottom_x) - (bottom_x-top_x)*(cy-w)
								+ (top_x-(cx-w))*2*w;
						}
					else
						if( left_y < cy+w ) // 3
						{
							diff = calc(Rtf, cx-w, cx+w) - (2*w)*(cy-w);
						}
						else // 4
						{
							diff = calc(Rtf, top_x, cx+w) - ((cx+w) - top_x)*(cy-w)
								+ (top_x-(cx-w))*2*w;
						}
					nonhitArea += diff;
				}
			}
	breakx:;
	}
	return (totalArea - nonhitArea*4) / totalArea;
}

int main()
{
	int N; cin >> N;
	for(int pid=1; pid<=N; ++pid)
	{
		double f,R,t,r,g; cin >> f >> R >> t >> r >> g;
		cout << "Case #" << pid << ": " << setiosflags(ios::fixed) << setprecision(6)
		     << solve(f,R,t,r,g) << endl;
	}
}
