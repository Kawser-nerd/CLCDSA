#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>


void do_one_case(int);


int main(int argc, char **argv)
{
  int N, cnum;

  scanf("%d\n", &N);

  for(cnum=1; cnum<=N; cnum++)
    {
      do_one_case(cnum);
    }

  return 0;
}


void do_one_case(int cnum)
{
  int i, j;
  double f, R0, t, r0, g0;
  double miss, R, g, r, s;

  assert(5==scanf("%lf %lf %lf %lf %lf\n", &f, &R0, &t, &r0, &g0));

  R = R0 - t - f;
  g = g0 - 2.0*f;
  r = r0 + f;
  miss = 0.0;

  if(R<=0.0 || g<=0.0)
      goto done;
      
  // norm everything to interior radius 1
  R0 /= R;
  g /= R;
  r /= R;
  s = g + 2*r;

  //fprintf(stderr, "R0=%g, g=%g, s=%g\n", R0, g, s);

  for(i=0; i<1010 && i*s<=1.0; i++)
    {
      double ylow, yhigh;
      double xlow, xhigh;

      ylow = i*s + r;
      xhigh = sqrt(1.0 - ylow*ylow);
      yhigh = ylow + g;
      if(yhigh < 1.0)
          xlow = sqrt(1.0 - yhigh*yhigh);
      else
        {
          xlow = 0.0;
          yhigh = 1.0;
        }

      j = (int) floor(xlow/s);
      miss += j * g*g;
      for(; j<1010 && j*s<xhigh; j++)
        {
          double a, b, c, d, A;
          a = b = j*s + r;
          c = d = a + g;
          //fprintf(stderr, "i=%d j=%d a=%g b=%g c=%g d=%g\n", i, j, a, b, c, d);
          if(a>xhigh)
            {
              A = 0.0;
              goto addarea;
            }
          if(d<xlow)
            {
              A = g*g;
              goto addarea;
            }
          if(b<xlow)
              b = xlow;
          else if(b>xhigh)
              b = xhigh;
          if(c>xhigh)
              c = xhigh;
          else if(c<xlow)
              c = xlow;
          //fprintf(stderr, "i=%d j=%d a=%g b=%g c=%g d=%g\n", i, j, a, b, c, d);
          assert(a<=b && b<=c && c<=d);
          A = (b-a)*(yhigh-ylow);
          A += .5*(c*sqrt(1.0-c*c) + asin(c) - b*sqrt(1.0-b*b) - asin(b));
          A -= (c-b)*ylow;
addarea:
          //fprintf(stderr, "i=%d j=%d A=%g (g^2=%g)\n", i, j, A, g*g);
          miss += A;
        }
      assert(j<1005);
    }
  assert(i<1005);

  miss *= 4.0/M_PI;     // adjust for size of quadrant
  miss /= R0*R0;        // adjust for outer radius

done:
  printf("Case #%d: %.9f\n", cnum, 1.0-miss);
}



