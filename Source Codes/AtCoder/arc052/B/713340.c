#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Volume_Cone(double r,double h);

typedef struct cone{
	double x_i;
	double x_t;
	double r;
	double h;
	double v;
}cone;

int main(void){
	cone *input;
	int n,q,a,b,i,j;
	double tmp;
	double sum;
	
	scanf("%d %d",&n,&q);
	input=(cone *)calloc(n,sizeof(cone));
	for(i=0;i<n;i++){
		scanf("%lf %lf %lf",&input[i].x_i,&input[i].r,&input[i].h);
		//printf("%f %f %f\r\n",input[i].x_i,input[i].r,input[i].h);
		input[i].x_t=input[i].x_i+input[i].h;
		input[i].v=Volume_Cone(input[i].r,input[i].h);
		//printf("Volume: %f\r\n",input[i].v);
	}
	//puts("next line is query.");
	for(i=0;i<q;i++){
		sum=0;
		scanf("%d %d",&a,&b);
		for(j=0;j<n;j++){
			if(input[j].x_i<a){
				if(input[j].x_t<=a) continue;
			//a<input[j].x_t<=b
				tmp=input[j].r*(input[j].x_t-a)/input[j].h;
				sum+=Volume_Cone(tmp,input[j].x_t-a);
				
				if(input[j].x_t>b){
					tmp=input[j].r*(input[j].x_t-b)/(input[j].h);
					sum-=Volume_Cone(tmp,input[j].x_t-b);
				}
			}else if(a<=input[j].x_i && input[j].x_i<b){
				sum+=input[j].v;
				if(input[j].x_t>b){
					tmp=input[j].r*(input[j].x_t-b)/(input[j].h);
					sum-=Volume_Cone(tmp,input[j].x_t-b);
				}
			}
		}
		printf("%f\r\n",sum);
	}
	
	free(input);
	return 0;
}

double Volume_Cone(double r,double h){
	double pi;
	pi=atan(1.0)*4;
	return r*r*pi*h/3;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&q);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf %lf",&input[i].x_i,&input[i].r,&input[i].h);
   ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^