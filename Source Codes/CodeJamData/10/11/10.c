/*
  TYTUŁ ZADANIA
  Author: Piotr Różański
  Compiler: GCC
*/

#include <stdio.h>

char tablica[100][100];
int zlicz[2][100][100];

int main(void)
{
  unsigned test, testy;
  scanf("%u\n",&testy);
  for (test=1; test<=testy; ++test)
  {
    int n,k;
    scanf("%d %d\n",&n,&k);
    
    int i,j,d;
    for (i=0; i<n; ++i)
    {
      char* wiersz = tablica[i];
      fgets(wiersz,sizeof*tablica,stdin);
      d = n;
      for (j=n-1; j>=0; --j) if (wiersz[j]!='.') wiersz[--d] = wiersz[j];
      while (d>0) wiersz[--d] = '.';
    }
    
    int Bma = 0;
    int Rma = 0;
    
    for (i=0; i<n; ++i)
    {
      d = tablica[i][0]!='.';
      for (j=1; j<n; ++j)
      {
        char nowy = tablica[i][j];
        char stary = tablica[i][j-1];
        if (nowy == '.') d = 0;
        else if (nowy == stary) ++d;
        else d = 1;
        
        if (d >= k)
        {
          if (nowy == 'B') Bma = 1;
          if (nowy == 'R') Rma = 1;
        }
      }
    }
        
    for (j=0; j<n; ++j)
    {
      d = tablica[0][j]!='.';
      for (i=1; i<n; ++i)
      {
        char nowy = tablica[i][j];
        char stary = tablica[i-1][j];
        if (nowy == '.') d = 0;
        else if (nowy == stary) ++d;
        else d = 1;
        
        if (d >= k)
        {
          if (nowy == 'B') Bma = 1;
          if (nowy == 'R') Rma = 1;
        }
      }
    }

    for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
    {
      char nowy = tablica[i][j];
      if (i && j)
      {
        char stary = tablica[i-1][j-1];
        if (nowy == '.') d = 0;
        else if (nowy == stary) d = zlicz[0][i-1][j-1] + 1;
        else d = 1;
        zlicz[0][i][j] = d;

        if (d >= k)
        {
          if (nowy == 'B') Bma = 1;
          if (nowy == 'R') Rma = 1;
        }
      }
      else zlicz[0][i][j] = (nowy != '.');
      
      if (i && j+1<n)
      {
        char stary = tablica[i-1][j+1];
        if (nowy == '.') d = 0;
        else if (nowy == stary) d = zlicz[1][i-1][j+1] + 1;
        else d = 1;
        zlicz[1][i][j] = d;

        if (d >= k)
        {
          if (nowy == 'B') Bma = 1;
          if (nowy == 'R') Rma = 1;
        }
      }
      else zlicz[1][i][j] = (nowy != '.');
    }

    printf("Case #%d: %s\n",test, Bma && Rma ? "Both" : Bma ? "Blue" : Rma ? "Red" : "Neither");
  }
  return 0;
}
