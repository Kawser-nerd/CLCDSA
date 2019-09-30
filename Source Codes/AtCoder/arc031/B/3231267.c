#include <stdio.h>
#include <string.h>



int map[10][10];
int reached[10][10];
int toutatu=0;

void search(int x, int y){
	if(x<0||x>9||y<0||y>9||map[x][y]=='x') return;
	if(reached[x][y]==1) return;
	
	reached[x][y]=1;
	toutatu++;
//	printf("(%d,%d)?? maze[%d][%d]=%c\n",x,y,x,y,maze[x][y]);
	
	search(x+1,y);
	search(x-1,y);
	search(x,y+1);
	search(x,y-1);
}

int main(void)
{
	//?????
	int i,j,k,l;
	int s[2];
	int menseki=0;
	int ans=0;
	
	//????????
	
//	scanf("%d %d\n",&h,&w);
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j]=='o'){
				s[0]=i;
				s[1]=j;
				menseki++;
			}
		}
		scanf("%*c",s);
	}
	
	
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			reached[i][j]=0;
		}
	}
	
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(map[i][j]=='x'){
				map[i][j]='o';
				search(s[0],s[1]);
				if(menseki+1==toutatu){
					ans=1;
				}
//				printf("??????????%d\n",toutatu);
				
				//?????????
				map[i][j]='x';
				toutatu=0;
				for(k=0;k<10;k++){
					for(l=0;l<10;l++){
						reached[k][l]=0;
					}
				}
			}
		}
	}
	
	
	
//	printf("??????\n");
	
	//??
	
	if(ans==1){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
//	printf("???????\n");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:10: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
    scanf("%c",&map[i][j]);
          ^
./Main.c:46:9: warning: too many arguments for format [-Wformat-extra-args]
   scanf("%*c",s);
         ^
./Main.c:39:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c",&map[i][j]);
    ^
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%*c",s);
   ^