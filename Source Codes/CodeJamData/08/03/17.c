#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// find size of circle segment
double segment(double xa, double ya, double xb, double yb, double R)
{
    double aang = atan2(ya, xa);
    double bang = atan2(yb, xb);

    double ang = (bang - aang);

    double area = R * R / 2 * (ang - sin(ang));

    return area;
}

double rect(double x1, double y1, double x2, double y2,
	    double R, double g)
{
    if (x2*x2 + y2*y2 < R*R) {
	return g*g;
    }
    else {
	//find intersection
	double intercept;
	double xa,ya,xb,yb;
	int a,b;

	intercept = sqrt(R*R - x2*x2);
	//	printf("First int: %lf\n",intercept);
	if (x2 > R || intercept < y1) {
	    xa = sqrt(R*R - y1*y1);
	    ya = y1;
	    a = 0;
	}
	else {
	    xa = x2;
	    ya = intercept;
	    a = 1;
	}

	intercept = sqrt(R*R - y2*y2);
	//	printf("Second int: %lf\n",intercept);
	if (y2 > R || intercept < x1) {
	    yb = sqrt(R*R - x1*x1);
	    xb = x1;
	    b = 0;
	}
	else {
	    yb = y2;
	    xb = intercept;
	    b = 1;
	}

	//	printf("Intercepts are (%lf,%lf) and (%lf,%lf)\n",xa,ya,xb,yb);
	
	if (a && b) {
	    //	    printf("Case 1\n");
	    return g*g - (y2-ya)*(x2 - xb)/2 + segment(xa,ya,xb,yb,R);
	}
	else if (!a && !b) {
	    //	    printf("Case 2\n");
	    return (yb - y1)*(xa - x1)/2 + segment(xa,ya,xb,yb,R);
	}
	else if (!a && b) {
	    //	    printf("Case 3\n");
	    return (xa + xb - 2*x1)*(y2-y1)/2 + segment(xa,ya,xb,yb,R);
	}
	else if (a && !b) {
	    //	    printf("Case 4\n");
	    return (ya + yb - 2*y1)*(x2-x1)/2 + segment(xa,ya,xb,yb,R);
	}
    }
}

void area()
{
    double f,R,t,r,g;
    double area;

    double x1,y1;
    double x2,y2;

    double prob;

    scanf("%lf %lf %lf %lf %lf",&f,&R,&t,&r,&g);

    //    printf("%lf %lf %lf %lf %lf\n",f,R,t,r,g);

    // inflate obstacles
    t = t + f;
    r = r + f;
    g = g - 2*f;

    //    printf("%lf %lf %lf %lf %lf\n",f,R,t,r,g);
    //    printf("%lf\n", R-t);
    if (g <= 0) {
	printf("%lf\n",1.0);
	return;
    }

    //    printf("%lf\n",rect(0,0.5,0.5,2,1,2));
    //    return;

    area = M_PI*R*R/4.0;

    x1 = r;
    while (x1 < (R - t)) {
	y1 = r;
	while (y1 < (R - t)) {
	    double a;
	    if (x1*x1 + y1*y1 > (R-t)*(R-t))
		break;
	    
	    x2 = x1 + g;
	    y2 = y1 + g;

	    a = rect(x1,y1,x2,y2,(R-t),g);
	    area -= a;
	    //	    printf("Rect at ((%lf,%lf),(%lf,%lf)) with area %lf\n",x1,x2,y1,y2,a);

	    y1 += g + 2*r;
	}
	x1 += g + 2*r;
    }

    prob = area/(M_PI*R*R/4.0);
    printf("%lf\n",prob);
}

int main(int argc, char *argv[])
{
    int cases;
    int i;

    scanf("%d", &cases);
    for (i = 0; i < cases; i++) {
	printf("Case #%d: ",(i+1));
	area();
    }

    return 0;
}
