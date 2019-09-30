#include<stdio.h>
#include<stdlib.h>

char grid[26][26];
int r, c;

int main(){
    int tcases, dsagrefd;
    scanf("%d", &tcases);
    for(dsagrefd = 0;dsagrefd < tcases;dsagrefd++){
	int i, j;
	scanf("%d %d", &r, &c);
	for(i = 0;i < r;i++){
	    scanf("%s", grid[i]);
	}

	for(i = 0;i < r;i++){
	    for(j = 1;j < c;j++){
		if(grid[i][j] == '?')
		    grid[i][j] = grid[i][j-1];
	    }
	    for(j = c-2;j >= 0;j--){
		if(grid[i][j] == '?')
		    grid[i][j] = grid[i][j+1];
	    }
	}

	for(i = 1;i < r;i++){
	    for(j = 0; j < c && grid[i][j] == '?';j++);
	    if(j == c){
		for(j = 0;j < c;j++){
		    grid[i][j] = grid[i-1][j];
		}
	    }
	}

	for(i = r-2;i >= 0;i--){
	    for(j = 0; j < c && grid[i][j] == '?';j++);
	    if(j == c){
		for(j = 0;j < c;j++){
		    grid[i][j] = grid[i+1][j];
		}
	    }
	}

	printf("Case #%d:\n", dsagrefd + 1);
	for(i = 0;i < r;i++){
	    printf("%s\n", grid[i]);
	}
    }
    return 0;
}
