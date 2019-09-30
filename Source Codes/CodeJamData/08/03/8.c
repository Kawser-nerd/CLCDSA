
#define _BSD_SOURCE

#include <stdio.h>
#include <math.h>

#define square(x) ((x)*(x))

static double circle_segment_area(double r, double alpha)
{
    return 0.5 * alpha * square(r);
}

static double circle_interval_area(double r, double a)
{
    return circle_segment_area(r, asin(a/r)) + 0.5 * a * sqrt(square(r) - square(a));
}

static double circle_intersect_infrect(double r, double x, double y)
{
    if (square(x) + square(y) > square(r))
	return 0.0;
    return square(r) * M_PI_4 - circle_interval_area(r, x) - circle_interval_area(r, y) + x*y;
}

static double circle_intersect_rect(double r, double x, double y, double w, double h)
{
    if (square(x+w) + square(y+h) <= square(r))
	return w*h;

    if (square(x+w) + square(y) > square(r))
    {
	if (square(x) + square(y+h) > square(r))
	    return circle_intersect_infrect(r, x, y);
	double t;
	/* mirror along first median */
	t = x; x = y; y = t;
	t = w; w = h; h = t;
    }

    return circle_interval_area(r, x+w) - circle_interval_area(r, x) - w*y - circle_intersect_infrect(r, x, y+h);
}

double prob(double outer, double inner, double r, double g)
{
    if (inner < 0.0 || g <= 0.0)
	return 1.0;

    double free_area = 0.0;
    for (double y = r; y < inner; y += g + 2*r)
	for (double x = r; square(x) + square(y) < square(inner); x += g + 2*r)
	    free_area += circle_intersect_rect(inner, x, y, g, g);
    free_area *= 4.0;

    double total_area = M_PI*square(outer);
    return 1.0 - free_area/total_area;
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
	double f, outer, thickness, r, g;
	scanf("%lf %lf %lf %lf %lf", &f, &outer, &thickness, &r, &g);

	double inner = outer - thickness - f;
	r += f;
	g -= 2*f;

	printf("Case #%d: %.6f\n", i, prob(outer, inner, r, g));
    }
}

