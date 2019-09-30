#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define MAXN 100
#define MAXSIZE 10000
#define PI 3.14159265358979323846264

#define QUAD_SQUARE 1
#define QUAD_ECHELON_V 2
#define QUAD_ECHELON_H 3
#define QUAD_TRANGLE 4
#define QUAD_ANTI_TRANGLE 5

typedef struct quadrange{
	int type;
	double rightup[2];
	double rightdown[2];
	double leftup[2];
	double leftdown[2];
} *Quad;


int n;
double df,R,t,r,g;
double cases[MAXN] = {0.0};
Quad quads[MAXN];
int nq = 0;
FILE *inf;

double xuanchuang(double height){
	return sqrt((R-t-df)*(R-t-df)-height*height);
}
int check(double x,double y){
	return sqrt(x*x+y*y) < (R-t-df);
}
double arcarea(double x1,double y1,double x2,double y2){
	double length;
	double alpha;
	double sinalgha;
	length = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/2;
	alpha = asin(length/(R-t-df))*2;
	sinalgha = sin(alpha);
	return (R-t-df)*(R-t-df)*(alpha-sinalgha)/2;
	
}
void getQuad(){
	int yindex = 0;
	int xindex = 0;
	double x,y;
	Quad tmp;
	for(yindex=0;(2*r+g)*yindex <= R;yindex++){
		for(xindex=0;(2*r+g)*xindex <= R;xindex++){
			x = (2*r+g)*xindex;
			y = (2*r+g)*yindex;
			if(check(x+r,y+r) && check(x+r+g,y+r) && check(x+r,y+r+g) && check(x+r+g,y+r+g)){
				tmp = malloc(sizeof(struct quadrange));
				tmp->type = QUAD_SQUARE;
				tmp->leftdown[0] = x+r+g;
				tmp->leftdown[1] = y+r;
				tmp->leftup[0] = x+r+g;
				tmp->leftup[1] = y+r+g;
				tmp->rightdown[0] = x+r;
				tmp->rightdown[1] = y+r;
				tmp->rightup[0] = x+r;
				tmp->rightup[1] = y+r+g;
				quads[nq++] = tmp;
			}
			if(check(x+r,y+r) && !check(x+r+g,y+r) && check(x+r,y+r+g) && !check(x+r+g,y+r+g)){
				tmp = malloc(sizeof(struct quadrange));
				tmp->type = QUAD_ECHELON_V;
				tmp->leftdown[0] = xuanchuang(y+r);
				tmp->leftdown[1] = y+r;
				tmp->leftup[0] = xuanchuang(y+r+g);
				tmp->leftup[1] = y+r+g;
				tmp->rightdown[0] = x+r;
				tmp->rightdown[1] = y+r;
				tmp->rightup[0] = x+r;
				tmp->rightup[1] = y+r+g;
				quads[nq++] = tmp;
			}
			if(check(x+r,y+r) && check(x+r+g,y+r) && !check(x+r,y+r+g) && !check(x+r+g,y+r+g)){
				tmp = malloc(sizeof(struct quadrange));
				tmp->type = QUAD_ECHELON_H;
				tmp->leftdown[0] = x+r+g;
				tmp->leftdown[1] = y+r;
				tmp->leftup[0] = x+r+g;
				tmp->leftup[1] = xuanchuang(x+r+g);
				tmp->rightdown[0] = x+r;
				tmp->rightdown[1] = y+r;
				tmp->rightup[0] = x+r;
				tmp->rightup[1] = xuanchuang(x+r);
				quads[nq++] = tmp;
			}
			if(check(x+r,y+r) && check(x+r+g,y+r) && check(x+r,y+r+g) && !check(x+r+g,y+r+g)){
				tmp = malloc(sizeof(struct quadrange));
				tmp->type = QUAD_ANTI_TRANGLE;
				tmp->leftdown[0] = x+r+g;
				tmp->leftdown[1] = y+r;
				tmp->leftup[0] = x+r+g;
				tmp->leftup[1] = xuanchuang(x+r+g);
				tmp->rightdown[0] = x+r;
				tmp->rightdown[1] = y+r;
				tmp->rightup[0] = xuanchuang(y+r+g);
				tmp->rightup[1] = y+r+g;
				quads[nq++] = tmp;
			}
			if(check(x+r,y+r) && !check(x+r+g,y+r) && !check(x+r,y+r+g) && !check(x+r+g,y+r+g)){
				tmp = malloc(sizeof(struct quadrange));
				tmp->type = QUAD_TRANGLE;
				tmp->leftdown[0] = xuanchuang(y+r);
				tmp->leftdown[1] = y+r;
				tmp->leftup[0] = 0;
				tmp->leftup[1] = 0;
				tmp->rightdown[0] = x+r;
				tmp->rightdown[1] = y+r;
				tmp->rightup[0] = x+r;
				tmp->rightup[1] = xuanchuang(x+r);
				quads[nq++] = tmp;
			}
		}
	}	
}

double quadarea(Quad qu){
	double arc;
	double tri;
	double echelon;
	if(qu->type == QUAD_SQUARE){
		return g*g;
	}else if(qu->type == QUAD_TRANGLE){
		arc = arcarea(qu->leftdown[0],qu->leftdown[1],qu->rightup[0],qu->rightup[1]);
		tri = (qu->leftdown[0]-qu->rightdown[0])*(qu->rightup[1]-qu->rightdown[1])/2;
		return tri+arc;
	}else if(qu->type == QUAD_ECHELON_H){
		arc = arcarea(qu->leftup[0],qu->leftup[1],qu->rightup[0],qu->rightup[1]);
		echelon = ((qu->leftup[1]-qu->leftdown[1])+(qu->rightup[1]-qu->rightdown[1]))*g/2;
		return arc+echelon;
	}else if(qu->type == QUAD_ECHELON_V){
		arc = arcarea(qu->leftdown[0],qu->leftdown[1],qu->leftup[0],qu->leftup[1]);
		echelon = (qu->leftup[0]-qu->rightup[0]+qu->leftdown[0]-qu->rightdown[0])*g/2;
		return arc+echelon;
	}else if(qu->type == QUAD_ANTI_TRANGLE){
		arc = arcarea(qu->leftup[0],qu->leftup[1],qu->rightup[0],qu->rightup[1]);
		echelon = g*g-(qu->leftdown[0]-qu->rightup[0])*(qu->rightup[1]-qu->leftup[1])/2;
		return arc+echelon;
	}
	return 0;
}

double green(){
	int i;
	double area = 0.0;
	double temp = 0.0;
	if(df>=g/2){
		area = PI*(R-t-df)*(R-t-df);
		return area;
	}else{
		/*area = (2*index*r+(index-1)*g)*(2*index*r+(index-1)*g) - (index-1)*(index-1)*(g-2*df)*(g-2*df);
		area1 = PI*(R-t-df)*(R-t-df);
		area2 = (2*index*r+(index-1)*g)*(2*index*r+(index-1)*g);
		area = area * area1 / area2;
		return area;*/
		g = g - 2 * df;
		r = r + df;
		nq = 0;
		getQuad();
		for(i=0;i<nq;i++){
			temp = quadarea(quads[i]);
			printf("%lf\n",temp);
			area +=temp;
		}
		g = g + 2 * df;
		r = r + df;
		return PI*R*R-area*4;
		
		
	}
	return 0.0;
}

double blue(){
	double area = 0.0;
	area = PI*((R)*(R)-(R-t-df)*(R-t-df));
	return area;
}

double sum(){
	double area = 0.0;
	area = PI*(R)*(R);
	return area;
}


void main(){
	int i;
	
	double greenarea = 0.0;
	double bluearea = 0.0;
	double sumarea = 0.0;
	double p = 0.0;
	inf = fopen("C-small.in","r");
	fscanf(inf,"%d",&n);
	for(i=1;i<=n;i++){
		fscanf(inf,"%lf %lf %lf %lf %lf",&df,&R,&t,&r,&g);
		sumarea = sum();
		greenarea = green();
		p = greenarea/sumarea;
		cases[i] = p;
	}

	inf = fopen("C-small.out","w");
	for(i=1;i<=n;i++)
		fprintf(inf,"Case #%d: %.6f\n",i,cases[i]);
	fclose(inf);
	
}