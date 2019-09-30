#include <stdio.h>
#include <string.h>
#include <malloc.h>
//??????????
int isblack(char **cell, int x, int y, int width, int height){
	int i, j;
	int result=1;
	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if((x+i>=0)&&(x+i<width)&&(y+j>=0)&&(y+j<height)){
				if(cell[y+j][x+i]=='.'){
					result &= 0;
				}
			}
		}
	}
	return result;
}

//??????????
int hasblack(char **cell, int x, int y, int width, int height){
	int i, j;
	int result=0;
	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if((x+i>=0)&&(x+i<width)&&(y+j>=0)&&(y+j<height)&&((i!=0)||(j!=0))){
				if(cell[y+j][x+i]=='#'){
					result |= 1;
				}
			}
		}
	}
	return result;
}

int generate1(char** cell, char**yoso, int width, int height){
	int x, y;
	int possible=1;
	for(y=0;y<height;y++){
		for(x=0;x<width;++x){
			yoso[y][x] = isblack(cell, x, y, width, height)?'#':'.';
		}
		yoso[y][width]='\0';
	}
	
	for(y=0;y<height;y++){
		for(x=0;x<width;++x){
			if(((yoso[y][x]=='.')&&(cell[y][x]=='#'))&&(!hasblack(yoso, x, y, width, height)))possible=0;
		}
	}
	return possible;
}
int main(){
	char **cell;
	char **yoso;
	int possible=1;
	int width, height;
	int x, y;
	scanf("%d %d", &height, &width);
	yoso = malloc(sizeof(char*)*height);
	cell = malloc(sizeof(char*)*height);
	for(y=0;y<height;y++){
		yoso[y]=malloc(sizeof(char)*101);
		cell[y]=malloc(sizeof(char)*101);
	}	
	for(y=0;y<height;y++){
		scanf("%s", cell[y]);
	}
	possible = generate1(cell, yoso, width, height);
	printf("%s\n", possible?"possible":"impossible");
	if(possible){
		for(y=0;y<height;y++){
			printf("%s\n", yoso[y]);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:59:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &height, &width);
  ^
./Main.c:67:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", cell[y]);
   ^