#include <stdio.h>

#include <math.h>

typedef long double REAL;

float read_number(void) { 
  float A; scanf("%g",&A);
  return A;
}

/* I hate globals but.... */
static REAL max_sq_error, r0;
double square_area(REAL x, REAL y, REAL d)
{
  if(x*x+y*y>=r0*r0) return 0.0;
  if((x+d)*(x+d)+(y+d)*(y+d)<=r0*r0) return d*d;
  if(d*d<max_sq_error) 
    return 0.5*d*d;
  d/=2;
  return 
    square_area(x,y,d) +
    square_area(x+d,y,d) +
    square_area(x,y+d,d) +
    square_area(x+d,y+d,d);
}

double test_case(void)
{
  REAL f, R, t, r, g;
  REAL Ssq;

  REAL Stotal, maxsq;
  REAL x,y,dx;
    
  f = read_number(); R = read_number();
  t = read_number(); r = read_number();
  g = read_number();

  /* The inner circle */
  r0 = R-t-f;

  /* Update string width to match the fly */
  r+=f; g -= 2*f;

  /* Test trivial case: fly doesn't fit */
  if(r0<0 || g<=0) return 0;

  /* Total circle area of 1/4 of circle*/
  Stotal = M_PI*R*R;

  /* Distant between square corners */
  dx=2*r+g;


  /* Maximal number of squares (in fact more than that) 4/PI times, but who cares */
  maxsq = M_PI*r0*r0/dx/dx;

  fprintf(stderr, "Debug: sq=%g\n", (double)maxsq);

  /* Maximal error of square area */
  max_sq_error = Stotal*1e-7/maxsq;
  
  for(Ssq=0,x=r; x<r0; x+=dx) {
    for(y=r; y<r0; y+=dx) {
      REAL t = square_area(x,y,g);
      if(t==0.0) break;
      Ssq+=t;
    }
  }
  return 4*Ssq/Stotal;
}


int main(void)
{
  int case_no, total_cases;

  total_cases = read_number();
  for(case_no=1; case_no<=total_cases; case_no++) 
    printf("Case #%d: %-9g\n", case_no, 1-test_case());
  return 0;
}
