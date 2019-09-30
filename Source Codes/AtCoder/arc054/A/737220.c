#include<stdio.h>
#include<float.h>

int main(void){
	double jun,han,l,x,y,s,d,nokori_jun,nokori_han;
	scanf("%lf%lf%lf%lf%lf",&l,&x,&y,&s,&d);
	if(s==d){
		printf("%f\n",0.0);
		return 0;
	}
	if(d>s){
		nokori_jun=d-s;
		if(nokori_jun<0){
			nokori_jun*=-1;
		}
		nokori_han=(l-d)+s;
		if(nokori_han<0){
			nokori_han*=-1;
		}
	}else{
		nokori_jun=(l-s)+d;
		if(nokori_jun<0){
			nokori_jun*=-1;
		}
		nokori_han=d-s;
		if(nokori_han<0){
			nokori_han*=-1;
		}
	}
	jun=nokori_jun/(double)(x+y);
	if(x-y!=0){
		if(x-y<0){
			han=nokori_han/(double)(x-y);
		}else{
			han=nokori_jun/(x-y);
		}
	}else{
		han=DBL_MAX;
	}
	if(jun<0){
		jun*=-1;
	}
	if(han<0){
		han*=-1;
	}
	printf("%.10f\n",jun>han?han:jun);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf%lf%lf%lf",&l,&x,&y,&s,&d);
  ^