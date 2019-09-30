#include <stdio.h>

int main(void){
	int D,G,ans=1e9,i;
	scanf("%d %d",&D,&G);
	int p[D+1],c[D+1];
	for(i=1;i<=D;i++)scanf("%d %d",&p[i],&c[i]);
	int list;
	//num << n ?num?2^n????
	//1 << D = 2^D
	for(list=0; list<(1<<D); list++){
		int score=0, num=0, rest_max;
		for(i=1; i<=D; i++){
			if(list>>(i-1) & 1){
			//list???i????????1????????
			//=> list?2?????i????????
				score += 100*i*p[i] + c[i];
				num += p[i];
			}
			else{
				rest_max = i;//??????
			}
		}
		if(score<G){
			int s1 = 100*rest_max;//????????????
			int need = (G-score+s1-1)/s1;
			if(need > p[rest_max]) continue;//?????????????
			num += need;
		}
		ans = ans<num? ans: num;	
	}
	printf("%d",ans);	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&D,&G);
  ^
./Main.c:7:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=D;i++)scanf("%d %d",&p[i],&c[i]);
                   ^