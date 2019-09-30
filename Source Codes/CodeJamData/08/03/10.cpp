#include<cmath>
#include<iostream>
#include<stack>
#include<vector>
#include<cassert>
using namespace std;

double R, t, r, g, dd;
void readData(){
	double f;
	scanf("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);
	t+=f;
	g-=2*f;
	r+=f;
	dd=(R-t)*(R-t);
}

bool trivial(){
	if( R - t <= 0 || g <= 0 )
		return true;
	return false;
}

bool USED[2021][2021];

bool &used(int x, int y){
	return USED[x+1010][y+1010];
}

void clearUsed(){
	memset(USED, 0, sizeof(USED));
}

struct pt{
	pt(double x, double y):x(x), y(y){}
	bool operator==(const pt &sec) const{
		return x==sec.x && y==sec.y;
	}
	double x, y;
};

double dist0(const pt &p){
	return p.x*p.x + p.y*p.y;
}

pt horizInter(const pt &p){
	return pt(sqrt(dd-p.y*p.y), p.y);
}

pt vertInter(const pt &p){
	return pt(p.x, sqrt(dd-p.x*p.x));
}

#define sqr(a) ((a)*(a))
double fieldPart(const pt &p1, const pt &p2){
	if(p1==p2)
		return 0;
	double field = (p1.x*p2.y-p1.y*p2.x)/2;
	if(field<0) field=-field;
	double alpha = asin(2*field/dd);
	assert(alpha*dd/2 - field>=0);
	return alpha*dd/2 - field;
}

double intersect(int x, int y){
	double ox=x*(g+2*r),
		   oy=y*(g+2*r);

	static vector<pt> inner;
	static vector<pt> outer;
	inner.clear();
	outer.clear();

	pt p(0,0);

	p=pt(r+ox, r+oy);
	if(dist0(p) <= dd) inner.push_back(p);
	else outer.push_back(p);

	p=pt(r+g+ox, r+oy);
	if(dist0(p) <= dd) inner.push_back(p);
	else outer.push_back(p);

	p=pt(r+g+ox, r+g+oy);
	if(dist0(p) <= dd) inner.push_back(p);
	else outer.push_back(p);

	p=pt(r+ox, r+g+oy);
	if(dist0(p) <= dd) inner.push_back(p);
	else outer.push_back(p);

	if(inner.size()==0)
		return -1;
	else if(inner.size()==4)
		return g*g;
	else if(inner.size()==1){
		pt hp = horizInter(inner.front()),
		   vp = vertInter(inner.front()),
		   p = inner.front();
		return (hp.x-p.x)*(vp.y-p.y)/2 + fieldPart(hp, vp);
	}
	else if(inner.size()==2){
		if(inner.front().x==inner.back().x){
			pt ap = horizInter(inner.front()),
			   bp = horizInter(inner.back()),
			   p = inner.front();
			return (ap.x-p.x+bp.x-p.x)*g/2 + fieldPart(ap, bp);
		}
		else{
			pt ap = vertInter(inner.front()),
			   bp = vertInter(inner.back()),
			   p = inner.front();
			return (ap.y-p.y+bp.y-p.y)*g/2 + fieldPart(ap, bp);
		}
	}
	else if(inner.size()==3){
		pt hp = horizInter(outer.front()),
		   vp = vertInter(outer.front()),
		   p = outer.front();
		return g*g - (p.x-hp.x)*(p.y-vp.y)/2 + fieldPart(hp, vp);
	}
}

int main(){
	int testCount; scanf("%d",&testCount);
	stack<pair<int,int> > S;
	for(int test=1; test<=testCount; test++){
		readData();
		double answer = 1;
		if(!trivial()){
			double whiteArea=0;
			clearUsed();
			S.push(make_pair(0,0));
			while(!S.empty()){
				int x=S.top().first,
					y=S.top().second;
				S.pop();

				if(!used(x,y)){
					used(x,y)=true;

					double q = intersect(x, y);
					if(q>=0){
						whiteArea+=q;
						for(int i=0; i<=1; i++)
							for(int j=0; j<=1; j++)
								S.push(make_pair(x+i,y+j));
					}
				}
			}
			answer = 1. - whiteArea / (R*R*M_PI/4.);
		}
		printf("Case #%d: %.6lf\n", test, answer);
	}
	return 0;
}
