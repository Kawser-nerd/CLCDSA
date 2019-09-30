#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int h[10];
char y[10][102];
int x[26] = {0};
int count = 0;
void print(const int *v, const int size)
{
    int stat = 0;
    int combo = 1;
  if (v != 0) {
        int i,j;
    for (i = 0; i < size; i++) {
        for(j=0;j<h[v[i]];j++){
            if(i == 0 && j == 0){
                combo = 1;
            }
            else if(j == 0 && y[v[i]][j] == y[v[i-1]][h[v[i-1]]-1]){
                combo++;
            }
            else if(y[v[i]][j] == y[v[i]][j-1]){

                combo++;
            }
            else{

                if(j == 0){

                    if(combo == x[y[v[i-1]][h[v[i-1]]-1]-'a']){

                        combo = 1;
                    }
                    else{
                        stat= 1;
                        break;
                    }
                }
                else{

                    if(combo == x[y[v[i]][j-1]-'a']){
                        combo=1;
                    }
                    else{
                        stat= 1;
                        break;
                    }
                }
            }
        }
        if(stat == 1)
            break;
    }
    if(stat == 0)
        count++;
  }
} // print


void swap(int *v, const int i, const int j)
{
  int t;
  t = v[i];
  v[i] = v[j];
  v[j] = t;
}
void rotateLeft(int *v, const int start, const int n)
{
  int tmp = v[start];
  int i;
  for (i=start; i < n-1; i++) {
    v[i] = v[i+1];
  }
  v[n-1] = tmp;
} // rotateLeft


void permute(int *v, const int start, const int n)
{
  print(v, n);
  if (start < n) {
    int i, j;
    for (i = n-2; i >= start; i--) {
      for (j = i + 1; j < n; j++) {
    swap(v, i, j);
    permute(v, i+1, n);
      } // for j
      rotateLeft(v, i, n);
    } // for i
  }
} // permute
void init(int *v, int N)
{
    int i;
  for (i = 0; i < N; i++) {
    v[i] = i;
  }
} // init



int main(){
    FILE *fp;
    fp = fopen("./answerC2.txt","w");
    int T;
     int m;
    scanf("%d",&T);
    int i,j,k;
    for(i=0;i<T;i++){
        count = 0;
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf(" %s",y[j]);
            h[j] = strlen(y[j]);
            for(k=0;k<h[j];k++){
                    x[y[j][k] - 'a']++;
                            }
        }
        int *v = (int*) malloc(sizeof(int)*10);
        init(v, m);
        permute(v, 0, m);
        free(v);
        fprintf(fp,"Case #%d: %d\n",i+1,count);
        for(j=0;j<26;j++){
            x[j] = 0;
        }

    }
    fclose(fp);
    return 0;
}
