#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>

#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define MP make_pair

#define sqr(x) ((x)*(x))

#define ITER 20000000

const double PI = acos(-1);

using namespace std;

typedef pair<double,double> PDD;

double getcirc(double R,double a)
{
    return sqrt(R*R - a*a);
}

bool incirc(double R,PDD pt)
{
    return pt.first*pt.first + pt.second*pt.second < R*R;
}

bool isinter(double R,PDD a, PDD b)
{
    return incirc(R,a) != incirc(R,b);
}

PDD getcross(double R,PDD a,PDD b)
{
    double ret;
    if(a.first == b.first)
    {
	ret = getcirc(R,a.first);
	a.second = ret;
	return a;
    }
    else
    {
	ret = getcirc(R,a.second);
	a.first = ret;
	return a;
    }
}

double getarea(double R,PDD a,double r)
{
    vector<PDD> V;
    PDD b = a;
    PDD c = a;
    PDD d = a;
    b.first += r;
    c.second += r;
    d.first += r;
    d.second += r;

    V.push_back(a);
    V.push_back(b);
    V.push_back(d);
    V.push_back(c);
    V.push_back(a);

    vector<PDD> pt;
    vector<PDD> pv;

    if(incirc(R,a) == false) return 0;

    pt.push_back(a);

    for(int i=1;i<V.size();i++)
    {
	if(incirc(R,V[i-1]) != incirc(R,V[i]))
	{
	    pt.push_back(getcross(R,V[i-1],V[i]));
	    pv.push_back(pt.back());
	}
	if(incirc(R,V[i]))
	{
	    pt.push_back(V[i]);
	}
    }

    double area=0;
    for(int i=1;i<pt.size();i++)
    {
	area += (pt[i].first - pt[i-1].first) * (pt[i].second + pt[i-1].second) / 2;
    }
    if(area < 0 ) area = -area;

//    cout << "base = " << area << endl;

    if(pv.size() == 2)
    {
//	cout << pv[0].first << " " << pv[0].second << " - " << pv[1].first << " " << pv[1].second << endl;

	double phi1,phi2;
	phi1 = atan2(pv[0].second,pv[0].first);
	phi2 = atan2(pv[1].second,pv[1].first);
	if(phi2 < phi1) swap(phi1,phi2);
	double pdiff = phi2 - phi1;

	double aa;

/*	printf("phi1 = %lf phi2 = %lf\n",phi1,phi2);

	cout << "pdiff = " << pdiff << endl;*/

	aa = R * R * (pdiff - sin(pdiff)) / 2;
//	cout << "arc area = " << aa << endl;
	area += aa;
    }

    // add pv
    return area;
}


void process(int tt)
{
    double f,R,t,r,g;
    srand(time(NULL));

    cin >> f >> R >> t >> r >> g;

    double totarea = R * R * PI / 4;
    double livearea = 0;

    int fail,good;

//    cout << f << " " << R << " " << t << " " << r << " " << g << endl;

    if(g > f+f)
    {
	for(double x = r+f; x < R-t-f; x += g+r+r)
	{
	    for(double y = r+f; ; y+= g+r+r)
	    {
		PDD p;
		double area;
		p.first = x;
		p.second = y;
		area = getarea(R-t-f,p,g-f-f);
		if(area < 1e-9) break;
		livearea += area;
	    }
	}
    }

  //  cout << totarea << " " << livearea << endl;

    printf("Case #%d: %.6lf\n",tt,(totarea - livearea) / totarea);
}

int main(void)
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
	process(t);
    }
}
