#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define A 50
#define DELTA 1e-100


double x, y, z, vx, vy, vz, t, d, vg;
int ffz, ff, tmp;

int main() {
	int i;
	const char infile[] = "input.txt";
	const char outfile[] = "output.txt";

	int testcases;
	int testcase;

	FILE *inf;
	FILE *outf;

	inf = fopen ( infile, "r" ); if ( inf == NULL ) { perror(infile); return 1; }
	outf = fopen ( outfile, "w" ); if ( outf == NULL ) { perror(outfile); return 1; }

	fscanf(inf, "%d", &testcases);

	for (testcase=0; testcase<testcases; testcase++) {

		fscanf(inf, "%d", &ffz);
		x=y=z=vx=vy=vz=0.0;

		for (ff=0; ff<ffz; ff++) {
			fscanf(inf, "%d", &tmp); x+=0.0+tmp;
			fscanf(inf, "%d", &tmp); y+=0.0+tmp;
			fscanf(inf, "%d", &tmp); z+=0.0+tmp;
			fscanf(inf, "%d", &tmp); vx+=0.0+tmp;
			fscanf(inf, "%d", &tmp); vy+=0.0+tmp;
			fscanf(inf, "%d", &tmp); vz+=0.0+tmp;
		}

		//fprintf(outf, "%.8f %.8f %.8f %.8f %.8f %.8f\n", x,y,z,vx,vy,vz);

		x/=ffz;
		y/=ffz;
		z/=ffz;
		vx/=ffz;
		vy/=ffz;
		vz/=ffz;

		//fprintf(outf, "%.8f %.8f %.8f %.8f %.8f %.8f\n", x,y,z,vx,vy,vz);


		vg = (vx*vx + vy*vy + vz*vz);
		if (vg<DELTA)
			t = -1;
		else
			t = -(x*vx + y*vy + z*vz)/vg;

		if (t<0) {
			t = 0.0;
			d = x*x+y*y+z*z;
		}
		else
			d = (x+vx*t)*(x+vx*t)+(y+vy*t)*(y+vy*t)+(z+vz*t)*(z+vz*t);

		d = sqrt(d);

		fprintf(outf, "Case #%d: %.8f %.8f\n", testcase+1, d, t);
	}

	return 0;
}
