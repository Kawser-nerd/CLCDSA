
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <string>
  #include <map>
  #include <algorithm>
  
  using namespace std;

  #define PI 3.14159265358979323846264338327950288
  
const int Cmaxn = 300 + 5;
const int Cmaxv = 2*Cmaxn;
const double Czero = 1e-8;
const double eps = 1e-8;

int N, M;
double X[15], Y[15];
double xA, xB, yA, yB;


double *CFL;
inline bool Ccmp( const int &a,const int &b )
{
  return CFL[a] < CFL[b];
}
struct Tcircle
{
  double x[Cmaxn],y[Cmaxn],r[Cmaxn];
  int n;
  bool valid[Cmaxn];
  double ans;
  
  template< class T > T sqr( T x )
  {
    return x*x;
  }
  void addC( double xx, double yy, double rr )
  {
    x[n] = xx;
    y[n] = yy;
    r[n] = rr;
    n++;
  }
  void kick()
  {
    ans = 0;
    for(int i=0;i<n;i++)
    {
      valid[i] = true;
      for( int j=0;j<n;j++) if(i!=j)
      {
	if( (r[i]<r[j] || (fabs(r[i]-r[j]) < eps && i<j) ) && sqr(x[i]-x[j])+sqr(y[i]-y[j]) < sqr(r[i]-r[j]) + eps)
	{
	  valid[i] = false;break;
	}
      }
    }
    
    int tmp = n;
    n = 0;
    for(int i=0;i<tmp;i++) if(valid[i])
    {
      x[n] = x[i];
      y[n] = y[i];
      r[n] = r[i];
      n++;
    }
    
    for(int i=0;i<n;i++)
    {
      valid[i] = false;
      for(int j=0;j<n;j++) if( i!=j )
	if( sqr(x[i]-x[j])+sqr(y[i]-y[j]) < sqr(r[i]+r[j]) )
	{
	  valid[i] = true;break;
	}
      if(!valid[i]) ans+=PI*r[i]*r[i];
    }
    
    tmp = n;
    n = 0;
    for(int i=0;i<tmp;i++) if(valid[i])
    {
      x[n] = x[i];
      y[n] = y[i];
      r[n] = r[i];
      n++;
    }    
  }
  
  double FL[Cmaxv],FR[Cmaxv];
  int tot,id[Cmaxv];
  double cl[Cmaxv],cr[Cmaxv];
  int ct;
  

  double arcarea( double r,double a )
  {
    return 0.5*r*r*(a-sin(a));
  }
  inline void fix( double &x )
  {
    while( x<-Czero ) x+=2*PI;
    while( x+Czero > 2*PI ) x-=2*PI;
  }
  void work()
  {
    double mid,dis,sp;
    double m1,m2;
    double last;
    double x1,y1,x2,y2;
    
    for(int i=0;i<n;i++)
    {
      tot = 0;
      for(int j=0;j<n;j++) if(i!=j && sqr(x[i]-x[j])+sqr(y[i]-y[j])  <sqr(r[i]+r[j]) )
      {
	mid = atan2(y[j]-y[i],x[j]-x[i]);
	dis = sqrt( sqr(x[i]-x[j]) + sqr( y[i]-y[j] ) );
	sp = 0.5*( sqr(r[i])+sqr(dis)-sqr(r[j]) )/r[i]/dis;
	sp = acos(sp);
	
	m1 = mid-sp;fix(m1);
	m2 = mid+sp;fix(m2);
	
	if( m1 + Czero < m2 )
	{
	  tot++;
	  FL[tot] = m1;
	  FR[tot] = m2;
	}else
	{
	  tot++;FL[tot] = m1;FR[tot] = 2*PI + Czero;
	  tot++;FL[tot] = -Czero;FR[tot] = m2;
	}
      }
      for(int j=1;j<=tot;j++) id[j] = j;
      CFL = FL;
      sort( id+1,id+tot+1,Ccmp );
      
      ct = 0;last = 0;
      for(int j=1;j<=tot;j++)
      {
	if( FL[id[j]] - Czero < last ) last = max(last,FR[id[j]]);else
	{
	  ct++;
	  cl[ct] = last;
	  cr[ct] = FL[id[j]];
	  last = FR[id[j]];
	}
      }
      
      if( last + Czero < 2*PI )
      {
	if( ct>=1 && cl[ct]<Czero ) cl[ct] = last-2*PI;else
	{
	  ct++;
	  cl[ct] = last;
	  cr[ct] = 2*PI;
	}
      }
      
      for(int j=1;j<=ct;j++)
      {
	ans+=arcarea(r[i],cr[j]-cl[j]);
	x1 = x[i] + r[i]*cos(cl[j]);
	y1 = y[i] + r[i]*sin(cl[j]);
	x2 = x[i] + r[i]*cos(cr[j]);
	y2 = y[i] + r[i]*sin(cr[j]);
	ans+=0.5*(y2*x1-x2*y1);
      }
    }
  }
  double CalcArea()
  {
    kick();
    work();
    return ans;
  }
};


  void init()
  {
		scanf("%d%d", &N, &M);
		scanf("%lf%lf", &xA, &yA);
		scanf("%lf%lf", &xB, &yB);
		for (int i = 0; i < M; ++ i)
			scanf("%lf%lf", &X[i], &Y[i]);
  }
  
  Tcircle T;
  
  void work()
  {
		for (int i = 0; i < M; ++ i)
		{
			T.n = 0;
			double dis = sqrt((xA - X[i]) * (xA - X[i]) + (yA - Y[i]) * (yA - Y[i]));
			T.addC(xA, yA, dis);
			double dis2 = sqrt((xB - X[i]) * (xB - X[i]) + (yB - Y[i]) * (yB - Y[i]));
			T.addC(xB, yB, dis2);
			double tmp = T.CalcArea();
			//printf("FDAJFDAF%.2lf\n", tmp);
			tmp = PI * dis * dis + PI * dis2 * dis2 - tmp;
			if (fabs(tmp) < eps) tmp = 0.0;
			printf("%.7lf", tmp);
			if (i == M - 1) printf("\n"); else printf(" ");
		}
  }
  
  int main()
  {
		freopen("D-small-attempt0.in", "r", stdin);
		int T;
		scanf("%d", &T);
		for (int k = 1; k <= T; ++ k)
		{
			printf("Case #%d: ", k);
			init();
			work();
		}
		return 0;
  }