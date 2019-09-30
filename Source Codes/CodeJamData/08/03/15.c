#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double d(double x, double y) {
	return sqrt(x * x + y * y);
}

double coord(double r, double x) {
	return sqrt(r * r - x*x);
}

double right_triangle_area(double x1, double y1, double x2, double y2) {
	return 0.5*(x2-x1)*(y2-y1);
}

double circular_segment_area(double r, double x1, double y1, double x2, double y2) {
	double h = d(x1-x2, y1-y2);
	double sina = 0.5*h/r;
	double angle = 2.0*asin(sina);
	double area = 0.5*r*r*(angle-sin(angle)); 
	return area;
}

double rectangle_area(double x1, double y1, double x2, double y2) {
	return (x2-x1)*(y2-y1);
}

int main() {
	unsigned ncases;
	scanf("%u\n", &ncases);
	for(unsigned ncase = 1; ncase <= ncases; ncase++) {
		double f, R, t, r, g, p = 0, x, y;
		scanf("%lf %lf %lf %lf %lf\n", &f, &R, &t, &r, &g);
		f = f / R;
		t = t / R;
		r = r / R;
		g = g / R;
		R = 1.0;

		if(g <= 2*f) p = 1.0;
		else {
			for(x = r; x < R-t; x += g+2.0*r) {
				for(y = r; y < R-t; y += g+2.0*r) {
					if(d(x+f,y+f)+f < R-t) {
						if(d(x+g-f,y+g-f)+f <= R-t) {
							/* Empty space inside racket */
							p += (g-2*f)*(g-2*f);
						} else {
							/* Empty space partially inside racket */
							if(d(x+f,y+g-f)+f >= R-t && d(x+g-f,y+f)+f >= R-t) {
								/* both corners outside inner circle 
								 * simplest to compute, area = triangle + circular segment */
								double ty = coord(R-t-f,x+f);
								double tx = coord(R-t-f,y+f);
								p += right_triangle_area(x+f, y+f, tx, ty);
								p += circular_segment_area(R-t-f, x+f, ty, tx, y+f);
							} else if(d(x+f,y+g-f)+f >= R-t) {
								/* top left corner outside inner circle 
								 * area = rectangle + triangle + circular segment */
								double ty1 = coord(R-t-f,x+f);
								double ty2 = coord(R-t-f,x+g-f);
								p += right_triangle_area(x+f, ty2, x+g-f, ty1);
								p += rectangle_area(x+f, y+f, x+g-f, ty2);
								p += circular_segment_area(R-t-f, x+f, ty1, x+g-f, ty2);

							} else if(d(x+g-f,y+f)+f >= R-t) {
								/* bottom right corner outside inner circle 
								 * area = rectangle + triangle + circular segment */
								double tx1 = coord(R-t-f, y+f);
								double tx2 = coord(R-t-f, y+g-f);
								p += right_triangle_area(tx2, y+f, tx1, y+g-f);
								p += rectangle_area(x+f, y+f, tx2, y+g-f);
								p += circular_segment_area(R-t-f, tx1, y+f, tx2, y+g-f);
							} else {
								/* only top right corner outside inner circle
								 * triangle + 3 rectangles */
								double tx = coord(R-t-f, y+g-f);
								double ty = coord(R-t-f, x+g-f);
								p += rectangle_area(x+f, y+f, tx, ty);
								p += rectangle_area(x+f, ty, tx, y+g-f);
								p += rectangle_area(tx, y+f, x+g-f, ty);
								p += right_triangle_area(tx, ty, x+g-f, y+g-f);
								p += circular_segment_area(R-t-f, tx, y+g-f, x+g-f, ty);
							}
						}
					}
				}
			}
			p *= 4.0;
			p /= PI*R*R;
			p = 1.0 - p;
		}
		printf("Case #%u: %.6lf\n", ncase, p);
	}
}
