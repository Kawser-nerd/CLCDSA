#include<stdio.h>
#include<math.h>

typedef unsigned nat;
typedef unsigned bool;
typedef double real;

#define false 0
#define true 1

real pi;

typedef struct {
	real x, y;
} vec;

typedef struct {
	vec c;
	real r;
} circ;

inline real sq(real x) {
	return x*x;
}

inline vec vec_dist(vec u, vec v) {
	return (vec) {v.x-u.x, v.y-u.y};
}

inline real vec_norm_2(vec v) {
	return sq(v.x) + sq(v.y);
}

inline real vec_norm(vec v) {
	return sqrt(vec_norm_2(v));
}

bool vec_circ_in(vec v, circ c) {
	return vec_norm_2(vec_dist(c.c, v)) <= sq(c.r);
}

real relative_angle(vec u, vec v) {
	real a;
	vec d;

	d = vec_dist(u, v);
	a = acos(d.x/vec_norm(d));
	if (d.y < 0)
		a = 2*pi - a;
	return a;
}

inline real relative_angle2(vec u, vec a, vec b) {
	return fabs(relative_angle(u, b) - relative_angle(u, a));
}

real chord_area(circ c, vec u, vec v) {
	real a, sec, tri;

	a = relative_angle2(c.c, u, v);
	sec = a*sq(c.r)/2;
	tri = sq(c.r)*sin(a)/2;
	return sec-tri;
}

vec circ_hline_inter(circ c, real y) {
	real rx, ry;

	ry = y-c.c.y;
	rx = sqrt(sq(c.r) - sq(ry));
	return (vec) {c.c.x+rx, y};
}

vec circ_vline_inter(circ c, real x) {
	real rx, ry;

	rx = x-c.c.x;
	ry = sqrt(sq(c.r)-sq(rx));
	return (vec) {x, c.c.y+ry};
}

inline real vec_tri_area(vec u) {
	return fabs(u.x*u.y/2);
}

real inter_area_cs_case2(circ c, real s) {
	vec u, v;

	u = circ_hline_inter(c, s);
	v = circ_vline_inter(c, s);

	return sq(s) - vec_tri_area(vec_dist(u, v)) + chord_area(c, u, v);
}

real inter_area_cs_case0(circ c, real s) {
	vec u, v;
	real tri, cho;

	u = circ_hline_inter(c, 0);
	v = circ_vline_inter(c, 0);

	tri = vec_tri_area(vec_dist(u, v));
	cho = chord_area(c, u, v);

	return tri + cho;
}

real inter_area_cs_case1(circ c, real s) {
	vec u, v;

	u = circ_vline_inter(c, 0);
	v = circ_vline_inter(c, s);

	return (u.y + v.y)*s/2 + chord_area(c, u, v);
}

real inter_area_cs(circ c, real s) {
	bool ia, ib;
	real t;

	if (!vec_circ_in((vec) {0, 0}, c))
		return 0;

	if (vec_circ_in((vec) {s, s}, c))
		return sq(s);

	ia = vec_circ_in((vec) {s, 0}, c);
	ib = vec_circ_in((vec) {0, s}, c);

	if (ia && ib)
		return inter_area_cs_case2(c, s);
	if (!ia && !ib)
		return inter_area_cs_case0(c, s);
	
	if (ib) {
		t = c.c.x;
		c.c.x = c.c.y;
		c.c.y = t;
	}

	return inter_area_cs_case1(c, s);
}

#if DEBUGING
int main() {
	circ c;
	real s;

	pi = acos(-1);

	while (scanf(" ( %lf , %lf ) %lf ~ %lf", &c.c.x, &c.c.y, &c.r, &s) == 4) {
		printf("%.12lf\n", inter_area_cs(c, s));
	}

	return 0;
}
#else

int main() {
	nat tc, ix, iy, cs;
	real f, R, t, r, g, ta, aa, ar, x, y, s;
	circ c;

	pi = acos(-1);
	
	scanf("%u", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);
		ta = pi*sq(R)/4;
		R-= t;

		aa = 0;
		for (ix = 0;; ++ix) {
			x = r + (g+2*r)*ix;
			if (x >= R)
				break;
			for (iy = 0;; ++iy) {
				y = r + (g+2*r)*iy;
				if (y >= R)
					break;
				c.c = (vec) {-x-f, -y-f};
				c.r = R-f;
				s = g-2*f;
				if (c.r > 0 && s > 0) {
					ar = inter_area_cs(c, s);
					aa+= ar;
				}
			}
		}

		printf("Case #%u: %.12lf\n", cs+1, 1.0-aa/ta);
	}

	return 0;
}

#endif




