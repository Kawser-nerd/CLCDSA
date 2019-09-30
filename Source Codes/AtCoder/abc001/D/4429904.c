#include<stdio.h>

int max(int a, int b)
{
  if(a >= b)
    return a;
  else
    return b;
}

int main()
{
  int n;
  scanf("%d", &n);
  int s[n], e[n];
  
  int cmp(const void* a, const void* b)
  {
    int i, j;
    i = *(int *)a;
    j = *(int *)b;
    return s[i] - s[j];
  }
  
  int i, tmp;
  for(i = 0; i < n; i++)
  {
    scanf("%d-%d", s + i, e + i);
    tmp = s[i] % 100;
    if(tmp % 10 < 5)
      tmp -= tmp % 10;
    else if(tmp % 10 > 5)
      tmp -= tmp % 10 - 5;
    s[i] = s[i] / 100;
    s[i] *= 100;
    s[i] += tmp;
    
    tmp = e[i] % 100;
    if(tmp % 10 < 5)
    {
      if(tmp % 10 != 0)
        tmp += 5 - tmp % 10;
    } else if(tmp % 10 > 5)
      tmp += 10 - tmp % 10;
    if(tmp == 60)
    {
      e[i] = e[i] / 100 + 1;
      e[i] *= 100;
    } else
    {
      e[i] = e[i] / 100;
      e[i] *= 100;
      e[i] += tmp;
    }
  }
  
  int indices[n];
  for(i = 0; i < n; i++)
    indices[i] = i;
  
  qsort(indices, n, sizeof(int), cmp);
  
  int s_[n], e_[n];
  s_[0] = s[indices[0]];
  e_[0] = e[indices[0]];
  int j = 0;
  for(i = 1; i < n; i++)
  {
    if(e_[j] >= s[indices[i]])
    {
      e_[j] = max(e_[j], e[indices[i]]);
    } else
    {
      j++;
      s_[j] = s[indices[i]];
      e_[j] = e[indices[i]];
    }
  }
  
  for(i = 0; i <= j; i++)
    printf("%04d-%04d\n", s_[i], e_[i]);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:61:3: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
   qsort(indices, n, sizeof(int), cmp);
   ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d-%d", s + i, e + i);
     ^