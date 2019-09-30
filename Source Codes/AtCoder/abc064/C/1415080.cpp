#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int n;
  int a[5000], color[9] ={};

  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for(int i = 0; i < n; i++){
    if(a[i] < 400)
      color[0]++;
    else if(a[i] < 800)
      color[1]++;
    else if(a[i] < 1200)
      color[2]++;
    else if(a[i] < 1600)
      color[3]++;
    else if(a[i] < 2000)
      color[4]++;
    else if(a[i] < 2400)
      color[5]++;
    else if(a[i] < 2800)
      color[6]++;
    else if(a[i] < 3200)
      color[7]++;
    else
      color[8]++;
  }

  int count = 0;
  for(int i = 0; i < 8; i++)
    if(color[i] != 0)
      count++;

  if(count)
    printf("%d %d\n", count, count + color[8]);
  else
    printf("1 %d\n",  count + color[8]);
  
  return 0;
}