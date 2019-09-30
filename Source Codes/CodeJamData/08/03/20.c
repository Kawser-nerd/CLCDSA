//---------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>

#define PI  3.1415926535897932385
double	 e=0.00000001;

//---------------------------------------------------------------------------

int inside(double x, double y, double R)
{
	return (x*x+y*y<R*R);
}
double penta (double xs, double ys, double xe, double ye, double R)
{
	double xn, yn, A, B, C, al;
	xn=sqrt(R*R-ye*ye);
	yn=sqrt(R*R-xe*xe);


	A=ye-yn;
	B=xe-xn;
	C=sqrt(A*A+B*B);
	al=acos(1-C*C/2/R/R);
	return (xn-xs)*(ye-ys)+(xe-xn)*(yn-ys)+(A*B/2)+(R*R*al/2-R*R*sin(al)/2);
}
double kvadr1 (double xs, double ys, double xe, double ye, double R)
{
	double yns, yne, A, B, C, al;
	yns=sqrt(R*R-xs*xs);
	yne=sqrt(R*R-xe*xe);


	A=yns-yne;
	B=xe-xs;
	C=sqrt(A*A+B*B);

	al=acos(1-C*C/2/R/R);

	return (yne-ys)*(xe-xs)+(A*B/2)+(R*R*al/2-R*R*sin(al)/2);

}
double kvadr2 (double xs, double ys, double xe, double ye, double R)
{

	double xns, xne, A, B, C, al;
	xns=sqrt(R*R-ys*ys);
	xne=sqrt(R*R-ye*ye);


	A=xns-xne;
	B=ye-ys;
	C=sqrt(A*A+B*B);

	al=acos(1-C*C/2/R/R);

	return (xne-xs)*(ye-ys)+(A*B/2)+(R*R*al/2-R*R*sin(al)/2);
}

double triag (double xs, double ys, double xe, double ye, double R)
{
	double xn, yn, A, B, C, al;
	xn=sqrt(R*R-ys*ys);
	yn=sqrt(R*R-xs*xs);

	A=yn-ys;
	B=xn-xs;
	C=sqrt(A*A+B*B);

	al=acos(1-C*C/2/R/R);
	return (A*B/2)+(R*R*al/2-R*R*sin(al)/2);
}

int main(int argc, char* argv[])
{
	FILE *fi, *fo;
	int i, j;
	int n;
	double f, R, t, r, g;
	double xs, ys, xe, ye;
	double S, Sf;
	double ans;

	float ff, fR, ft, fr, fg;

	int c1, c2, c3, c4;
	double s1, s2, s3, s4;

	fi=fopen (argv[1], "r");
	fo=fopen (argv[2], "w");

	fscanf(fi, "%d" , &n);

	for (i = 0; i <n; i++)
	{
		S=0;
		c1=0;
		c2=0;
		c3=0;
		c4=0;

		s1=0;
		s2=0;
		s3=0;
		s4=0;

		fscanf(fi,"%f %f %f %f %f", &ff, &fR, &ft, &fr, &fg);
		f=ff;
		R=fR;
		t=ft;
		r=fr;
		g=fg;
		if (2*f-g>-e)
		{
			fprintf(fo, "Case #%d: %.6f\n", i+1,1.0);
			continue;
		}
		Sf=R*R*PI/4;
		xs=r;
		R-=t;
		while (xs<R)
		{
			xe=xs+g;
			ys=r;
			while (inside(xs+f, ys-f, R-f))
			{
				ye=ys+g;

				if (inside((xs+f), (ys+f), R-f)&&inside((xe-f), (ys+f), R-f)&&inside((xs+f), (ye-f), R-f)&&inside((xe-f), (ye-f), R-f))
				{
					S+=((xe-f)-(xs+f))*((ye-f)-(ys+f));
					s1+=((xe-f)-(xs+f))*((ye-f)-(ys+f));
					c1++;
				}
				else
				if (inside((xs+f), (ys+f), R-f)&&inside((xe-f), (ys+f), R-f)&&inside((xs+f), (ye-f), R-f)&&!inside((xe-f), (ye-f), R-f))
				{
					S+=penta((xs+f), (ys+f), (xe-f), (ye-f), R-f);
					s2+=penta((xs+f), (ys+f), (xe-f), (ye-f), R-f);
					c2++;
				}
				else
				if (inside((xs+f), (ys+f), R-f)&&inside((xe-f), (ys+f), R-f)&&!inside((xs+f), (ye-f), R-f)&&!inside((xe-f), (ye-f), R-f))
				{
					S+=kvadr1((xs+f), (ys+f), (xe-f), (ye-f), R-f);
					s3+=kvadr1((xs+f), (ys+f), (xe-f), (ye-f), R-f);

					c3++;
				}
				else
				if (inside((xs+f), (ys+f), R-f)&&!inside((xe-f), (ys+f), R-f)&&inside((xs+f), (ye-f), R-f)&&!inside((xe-f), (ye-f), R-f))
				{
					S+=kvadr2((xs+f), (ys+f), (xe-f), (ye-f), R-f);
					s3+=kvadr2((xs+f), (ys+f), (xe-f), (ye-f), R-f);

					c3++;
				}
				else
				if (inside((xs+f), (ys+f), R-f)&&!inside((xe-f), (ys+f), R-f)&&!inside((xs+f), (ye-f), R-f)&&!inside((xe-f), (ye-f), R-f))
				{
					S+=triag((xs+f), (ys+f), (xe-f), (ye-f), R-f);
					s4+=triag((xs+f), (ys+f), (xe-f), (ye-f), R-f);

					c4++;

				}

				//обработка
				ys=ye+2*r;
			}
			xs=xe+2*r;
		}

			ans=1.0-1.0*S/Sf; //(int)(1000000*S/Sf)/1000000;
			fprintf(fo, "Case #%d: %.6f\n", i+1, (float)ans);

//			fprintf(fo, "Case #%d: %.6f \nFull: %.6f \nDyrka: %.6f\nc1=%d\nc2=%d\nc3=%d\nc4=%d\n\ns1=%f\ns2=%f\ns3=%f\ns4=%f\n\n===================\n", i+1,1.0-S/Sf, Sf, S, c1, c2, c3, c4, s1, s2, s3, s4);
	}


	fclose(fi);
	fclose(fo);
	return 0;

}
//---------------------------------------------------------------------------
