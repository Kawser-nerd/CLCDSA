#include <stdio.h>
#include <stdbool.h>
#define Row 10
#define Column 10

void dfs(int x,int y);
void initialize( bool reached[Row][Column] );

int i,j;
char A[Row][Column];
bool reached[Row][Column];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int flg = 0;
int riku_count=0,srow,scolumn,count=0;

int main(){
    for(i=0;i<10;i++){
        scanf("%s",A[i]);
    }

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if( A[i][j] == 'o' ){
                riku_count++;
                if( flg == 0 ){
                    srow = i;
                    scolumn = j;
                    flg++;
                }
            }       
        }
    }

    if( riku_count == 100 ){
        printf("YES\n");
        return 0;
    }

    for(i=0;i<Row;i++){
        for(j=0;j<Column;j++){
            if( A[i][j] == 'x' ){
                A[i][j] = 'o';
                dfs(srow,scolumn);
                if( count == riku_count + 1 ){
                    printf("YES\n");
                    return 0;
                }
                A[i][j] = 'x';
                count = 0;
                initialize(reached);
            }
        }
    }

    printf("NO\n");

    return 0;
}

void dfs(int x,int y){
    if( x < 0 || Row <= x || y < 0 || Column <= y || A[x][y] == 'x' ){
        return;
    }
    if( reached[x][y] == true ){
        return;
    }
    if( A[x][y] == 'o' ){
        count++;
    }
    
    reached[x][y] = true;

    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

void initialize( bool reached[Row][Column] ){
    int a,b;
    for(a=0;a<Row;a++){
        for(b=0;b<Column;b++){
            reached[a][b] = false;
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",A[i]);
         ^