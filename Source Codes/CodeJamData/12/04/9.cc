#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define ASSERT(p) do { if (!(p)) { fprintf(stderr, "Assertion %s failed.\n", #p); exit(-1); } } while (0)

int gcd(int x, int y) {
    while (x != 0) {
	int tmp = x;
	x = y % x;
	y = tmp;
    }
    return y;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

void initial_position(int h, int w, char m[32][32], int *x, int *y) {
    for (int i = 0; i < h; ++i) {
	for (int j = 0; j < w; ++j) {
	    if (m[i][j] == 'X') {
		*x = i;
		*y = j;
		return;
	    }
	}
    }
    std::cerr << "Found no 'X'.\n";
    exit(-1);
    return;
}

struct rational {
    int n, d;
    rational() : n(0), d(0) { }
    rational(int _n, int _d) : n(_n), d(_d) {
	ASSERT(d != 0);
	reduce();
    }
    void reduce() {
	if (d < 0) {
	    d = -d;
	    n = -n;
	}
	int g = gcd(abs(n), d);
	n = n / g;
	d = d / g;
    }
    double as_double() const {
	return double(n) / double(d);
    }
};

rational operator+(rational a, rational b) {
    return rational(a.n * b.d + b.n * a.d, a.d * b.d);
}

rational operator-(rational a) {
    a.n = -a.n;
    return a;
}

rational operator-(rational a, rational b) {
    return a + (- b);
}

rational operator/(rational a, rational b) {
    rational r(a.n * b.d, a.d * b.n);
    return r;
}

rational operator*(rational a, rational b) {
    rational r(a.n * b.n, a.d * b.d);
    return r;
}

bool operator<(rational a, rational b) {
    return a.n * b.d < b.n * a.d;
}

bool operator>=(rational a, rational b) {
    return !(a < b);
}

bool operator==(rational a, rational b) {
    return a.n == b.n && a.d == b.d;
}

rational abs(rational r) {
    r.n = abs(r.n);
    r.d = abs(r.d);
    return r;
}

int floor(rational r) {
    if (r.n >= 0) { return r.n / r.d; }
    if (r.d == 1) { return r.n; }
    return -(1 + (-r.n) / r.d);
}

rational ratfloor(rational r) {
    return rational(floor(r), 1);
}

int ceiling(rational r) {
    return - floor(- r);
}

rational ratceiling(rational r) {
    return rational(ceiling(r), 1);
}



bool is_integer(rational r) {
    return r.d == 1;
}

struct position {
    rational x, y;
};

bool operator==(position p, position q) {
    return p.x == q.x && p.y == q.y;
}

struct direction {
    int dx, dy;
    direction() : dx(0), dy(0) { }
    direction(int _dx, int _dy) : dx(_dx), dy(_dy) { }

    bool is_invalid() const { return dx == 0 && dy == 0; }
};

struct total_distance {
    rational x_distance;
    rational y_distance;
    rational dee_squared;
    explicit total_distance(int d) : x_distance(0, 1), y_distance(0, 1), dee_squared(d * d, 1) { }
    explicit total_distance(total_distance *copyee) : x_distance(copyee->x_distance),
						      y_distance(copyee->y_distance),
						      dee_squared(copyee->dee_squared) { }
    bool greater() {
	return dee_squared < x_distance * x_distance + y_distance * y_distance;
    }

    double so_far() {
        double x = x_distance.as_double();
        double y = y_distance.as_double();
	return sqrt(x*x + y*y);
    }
private:
    total_distance(const total_distance&);
    void operator=(const total_distance&);
};

position change_point(position p, rational delta_x, rational delta_y, total_distance *totaler) {
    totaler->x_distance = totaler->x_distance + abs(delta_x);
    totaler->y_distance = totaler->y_distance + abs(delta_y);

    p.x = p.x + delta_x;
    p.y = p.y + delta_y;
    return p;
}

position change_y(position p, direction d, rational by, total_distance *totaler) {
    // change p.x by (dx/dy)*delta_y, change p.y by delta_y.  delta_y
    // = sign(d.dy) * by.

    ASSERT(d.dy != 0);
    rational delta_y = d.dy > 0 ? by : -by;

    return change_point(p, rational(d.dx, d.dy) * delta_y, delta_y, totaler);
}

position change_x(position p, direction d, rational by, total_distance *totaler) {
    // change p.y by (dy/dx)*delta_x, change p.x by delta_x.  delta_x
    // = sign(d.dx) * by.

    ASSERT(d.dx != 0);
    rational delta_x = d.dx > 0 ? by : -by;

    return change_point(p, delta_x, rational(d.dy, d.dx) * delta_x, totaler);
}

int get_x_neighbor(position pos, direction dir) {
    ASSERT(is_integer(pos.x));
    ASSERT(dir.dx != 0);
    int x = pos.x.n;
    return dir.dx > 0 ? x : x - 1;
}

int get_y_neighbor(position pos, direction dir) {
    ASSERT(is_integer(pos.y));
    ASSERT(dir.dy != 0);
    int y = pos.y.n;
    return dir.dy > 0 ? y : y - 1;
}

void entering_square(position pos, direction dir, int *x, int *y) {
    if (is_integer(pos.x)) {
	*x = get_x_neighbor(pos, dir);
    } else {
	*x = floor(pos.x);
    }
    if (is_integer(pos.y)) {
	*y = get_y_neighbor(pos, dir);
    } else {
	*y = floor(pos.y);
    }
}

direction boundary_redirect(char m[32][32], position pos, direction dir) {
    if (is_integer(pos.x)) {
	if (is_integer(pos.y)) {
	    // corner case!

	    int x_neigh, x_prev, y_neigh, y_prev;
	    {
		int x = pos.x.n;
		int y = pos.y.n;
		x_neigh = get_x_neighbor(pos, dir);
		y_neigh = get_y_neighbor(pos, dir);
		x_prev = x_neigh == x ? x - 1 : x;
		y_prev = y_neigh == y ? y - 1 : y;
	    }

	    if (m[x_neigh][y_prev] == '#') {
		if (m[x_neigh][y_neigh] == '#') {
		    if (m[x_prev][y_neigh] == '#') {
			// bounceback
			return direction(-dir.dx, -dir.dy);
		    } else {
			// x neighbors '#', y neighbor not.
			return direction(-dir.dx, dir.dy);
		    }
		} else {
		    // touches edge, no change.
		    return dir;
		}
	    } else {
		if (m[x_neigh][y_neigh] == '#') {
		    if (m[x_prev][y_neigh] == '#') {
			// y neighbors '#', x neighbor not.
			return direction(dir.dx, -dir.dy);
		    } else {
			// absorbs laser
			return direction(0, 0);
		    }
		} else {
		    // touches edge, no change.
		    return dir;
		}
	    }

	} else {
	    // x edge.
	    int x_neigh = get_x_neighbor(pos, dir);
	    if (m[x_neigh][floor(pos.y)] == '#') {
		return direction(-dir.dx, dir.dy);
	    } else {
		return dir;
	    }
	}
    } else {
	ASSERT(is_integer(pos.y));
	// y edge.
	int y_neigh = get_y_neighbor(pos, dir);
	if (m[floor(pos.x)][y_neigh] == '#') {
	    return direction(dir.dx, -dir.dy);
	} else {
	    return dir;
	}
    }
}

position midpoint(int x, int y) {
    position p;
    p.x = rational(x, 1) + rational(1, 2);
    p.y = rational(y, 1) + rational(1, 2);
    return p;
}

bool intersects_middle(position p, direction d, int x, int y, total_distance *totaler) {
    total_distance copy(totaler);

    if (is_integer(p.x)) {
	position p2 = change_x(p, d, rational(1, 2), &copy);
	return (p2 == midpoint(x, y) && !copy.greater());
    }
    if (is_integer(p.y)) {
	position p2 = change_y(p, d, rational(1, 2), &copy);
	return (p2 == midpoint(x, y) && !copy.greater());
    }
    ASSERT(false);
}

position reposition(position pos, direction dir, int target_x, int target_y, total_distance *totaler) {
    if (is_integer(pos.x)) {
	// how far in the x direction can we get?

	if (dir.dy == 0) {
	    return change_x(pos, dir, rational(1, 1), totaler);
	}

	// delta_y is (dy / dx) * delta_x
	// delta_x is (dx/dy) * delta_y
	rational room = dir.dy < 0 ? pos.y - rational(target_y, 1) : rational(target_y + 1, 1) - pos.y;

	rational dist_x = abs(rational(dir.dx, dir.dy)) * room;

	//	printf("room = %f (%d/%d),  dist_x = %f (%d/%d)\n",
	//	       room.as_double(), room.n, room.d,
	//	       dist_x.as_double(), dist_x.n, dist_x.d);

	if (rational(1, 1) < dist_x) {
	    dist_x = rational(1, 1);
	}

	return change_x(pos, dir, dist_x, totaler);
    } else {
	ASSERT(is_integer(pos.y));

	if (dir.dx == 0) {
	    return change_y(pos, dir, rational(1, 1), totaler);
	}

	rational room = dir.dx < 0 ? pos.x - rational(target_x, 1) : rational(target_x + 1, 1) - pos.x;

	rational dist_y = abs(rational(dir.dy, dir.dx)) * room;
	if (rational(1, 1) < dist_y) {
	    dist_y = rational(1, 1);
	}

	return change_y(pos, dir, dist_y, totaler);
    }
}


bool compute_reflects(int h, int w, int d, char m[32][32], int dx, int dy) {
    //    printf("compute_reflects %d %d %d ... %d %d\n", h, w, d, dx, dy);
    total_distance totaler(d);

    int x, y;
    initial_position(h, w, m, &x, &y);

    position pos = midpoint(x, y);
    direction dir(dx, dy);

    // Move to edge of first square.
    if (abs(dx) < abs(dy)) {
	// travel 0.5 in y direction, something in x direction.
	pos = change_y(pos, dir, rational(1, 2), &totaler);
    } else {
	// travel 0.5 in x direction, something in y direction.
	pos = change_x(pos, dir, rational(1, 2), &totaler);
    }

    for (;;) {

	//	printf("traveled %f so far at position (%f,%f) (%d/%d, %d/%d) direction (%d,%d)...\n",
	//	       totaler.so_far(),
	//	       pos.x.as_double(), pos.y.as_double(),
	//	       pos.x.n, pos.x.d, pos.y.n, pos.y.d,
	//	       dir.dx, dir.dy
	//	       );

	if (totaler.greater()) {
	    return false;
	}

	// Now we're on the edge of the square.

	dir = boundary_redirect(m, pos, dir);

	if (dir.is_invalid()) {
	    return false;
	}

	// Now we're entering a square.


	int target_x, target_y;
	entering_square(pos, dir, &target_x, &target_y);

	//	printf("redirected to (%d,%d), entering square %d,%d\n", dir.dx, dir.dy, target_x, target_y);



	if (target_x == x && target_y == y && intersects_middle(pos, dir, x, y, &totaler)) {
	    return true;
	}

	// now to move to the other side of the square

	pos = reposition(pos, dir, target_x, target_y, &totaler);

    }

}

int main() {
    int num_cases;
    std::cin >> num_cases;

    for (int casenum = 1; casenum <= num_cases; ++casenum) {
	int h, w, d;
	std::cin >> h >> w >> d;
	char m[32][32];

	int dh = getchar();
	if (dh != '\n') {
	    std::cerr << "Expecting newline!  got " << dh << std::endl;
	}

	for (int i = 0; i < h; ++i) {
	    for (int j = 0; j < w; ++j) {
		m[i][j] = getchar();
	    }
	    int ch = getchar();
	    if (ch != '\n') {
		std::cerr << "Expecting newline!  got " << ch << std::endl;
		return 1;
	    }
	}

	// Generally speaking, you can travel vert and horiz (easy) and directions of form
	// (x,y) where x, y \in Z, ||(x,y)|| <= D.

	// So this is brute-forceable and doable with careful programming.

	int count = 0;

	for (int dx = -d; dx <= d; ++dx) {
	    for (int dy = -d; dy <= d; ++dy) {
		if (dx * dx + dy * dy <= d * d
		    && gcd(abs(dx), abs(dy)) == 1) {
		    bool reflects = compute_reflects(h, w, d, m, dx, dy);
		    if (reflects) {
			count += 1;
		    }
		}
	    }
	}

	std::cout << "Case #" << casenum << ": " << count << std::endl;
    }
}
