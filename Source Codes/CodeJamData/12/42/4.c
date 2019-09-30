#include<stdio.h>

int main(){
    int test, run = 0, n, w, l;
    scanf("%d",&test);
    while(run<test){
	scanf("%d %d %d",&n,&w,&l);
	printf("Case #%d: ",run+1);
	int height = 0, dis = 0;
	int count = 0, radius, maxr=0;
	while(count < n){
	    scanf("%d", &radius);
	    if(dis + radius > w){
		if(height == 0)
		    height += maxr;
		else
		    height += 2*maxr;
		maxr = 0;
		dis = 0;
	    }
	    if(radius > maxr)
		maxr = radius;
	    if(dis == 0){
		if(height == 0)
		    printf("0 0 ");
		else
		    printf("0 %d ",height + radius);
		dis += radius;
	    }
	    else{
		if(height == 0)
		    printf("%d 0 ",dis + radius);
		else
		    printf("%d %d ",dis + radius, height+radius);
		dis += 2*radius;
	    }
	    count++;
	}
	printf("\n");
	run++;
    }
    return 0;
}
