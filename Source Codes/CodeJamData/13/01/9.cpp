#include<stdio.h>
#include<stdlib.h>
#include <string>
#include<math.h>

using namespace std;

int main(){
	int casenum;
	int r[4][2],l[4][2],d[2][2];
	scanf("%d\n",&casenum);
	for(int i=0;i<casenum;i++){
		for(int j=0;j<4;j++){
			r[j][0]=r[j][1]=l[j][0]=l[j][1]=d[j/2][0]=d[j/2][1]=0;
		}
		bool finish=true;
		int win=0;
		for(int j=0;j<4;j++){
			char str[6];
			scanf("%s",&str);
			for(int k=0;k<4;k++){
				switch(str[k]){
				case 'X':
					r[j][0]++;
					if(r[j][0]>=4)win=1;
					l[k][0]++;
					if(l[k][0]>=4)win=1;
					if(k==j)d[0][0]++;
					if(d[0][0]>=4)win=1;
					if(k+j==3)d[1][0]++;
					if(d[1][0]>=4)win=1;
					break;
				case 'O':
					r[j][1]++;
					if(r[j][1]>=4)win=2;
					l[k][1]++;
					if(l[k][1]>=4)win=2;
					if(k==j)d[0][1]++;
					if(d[0][1]>=4)win=2;
					if(k+j==3)d[1][1]++;
					if(d[1][1]>=4)win=2;
					break;
				case 'T':
					r[j][1]++;
					if(r[j][1]>=4)win=2;
					l[k][1]++;
					if(l[k][1]>=4)win=2;
					if(k==j)d[0][1]++;
					if(d[0][1]>=4)win=2;
					if(k+j==3)d[1][1]++;
					if(d[1][1]>=4)win=2;
					r[j][0]++;
					if(r[j][0]>=4)win=1;
					l[k][0]++;
					if(l[k][0]>=4)win=1;
					if(k==j)d[0][0]++;
					if(d[0][0]>=4)win=1;
					if(k+j==3)d[1][0]++;
					if(d[1][0]>=4)win=1;
					break;
				case '.':
					finish=false;
					break;
				default:
					break;
				}
			}
			
		}
		if(win==1){
				printf("Case #%d: X won\n",i+1);
			}else if(win==2){
				printf("Case #%d: O won\n",i+1);
			}else if(finish){
				printf("Case #%d: Draw\n",i+1);
			}else{
				printf("Case #%d: Game has not completed\n",i+1);
			}
	}
	//while(1);
	return 0;
}