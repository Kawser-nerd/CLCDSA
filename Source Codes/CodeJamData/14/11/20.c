#include<stdio.h>
#include<string.h>

char avai[151][50];
char req[151][50];
int n,l;

void display(char temp[151][50])
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
       printf("%s ",temp[i]);
}

void sort(char temp[151][50])
{
    int i,j;
    char dest[100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(temp[j],temp[j+1]) > 0)
            {
               strcpy(dest,temp[j]);
               strcpy(temp[j],temp[j+1]);
               strcpy(temp[j+1],dest);
            }
        }
    }
}
int compare(char temp[151][50])
{
      int i;
      int flag=0;
      for(i=0;i<n;i++)
      {
          if(strcmp(temp[i],avai[i]) != 0)
          {
              flag = 1;
              break;
          }
      }
      if(flag == 0)
         return 1;
      else
         return 0;
}
int find(char temp[151][50],int ind,int how_many)
{

    int i,j;

    if(ind == l)
    {

          char temp2[151][50];


          for(i=0;i<n;i++)
          {
              temp[i][ind] = '\0';
          }

          for(i=0;i<n;i++)
            strcpy(temp2[i],temp[i]);
          sort(temp2);
          //display(temp2);

          if(compare(temp2) == 1)
          {
            // printf("\nhere %d\n",how_many);
             return how_many;
          }
          else
           return -1;
    }
    else
    {
          for(i=0;i<n;i++)
          {
              temp[i][ind] = req[i][ind];
          }
          int min1 = find(temp,ind+1,how_many);
          //printf("\nddd = ");
          for(i=0;i<n;i++)
          {
              temp[i][ind] = '0' + (1 - (req[i][ind] - '0'));
           //   printf("%c ",temp[i][ind]);
          }
//          printf("\n");
          int min2 = find(temp,ind+1,how_many+1);

          if(min1 == -1 && min2 == -1)
             return -1;
          else if(min1 == -1)
             return min2;
          else if(min2 == -1)
             return min1;
          else
             return min1>min2?min2:min1;
    }
}
int main()
{
    int t,test_case,i;

    char st[100];
    char temp[151][50];

    scanf("%d",&test_case);

    t=1;

    while(t <= test_case)
    {
        scanf("%d %d",&n,&l);

        for(i=0;i<n;i++)
        {
            scanf("%s",avai[i]);
        }
        sort(avai);
        //display(avai);
        for(i=0;i<n;i++)
        {
            scanf("%s",req[i]);
        }
        int min = find(temp,0,0);
        printf("Case #%d: ",t);
        if(min == -1)
            printf("NOT POSSIBLE\n");
        else
           printf("%d\n",min);

       t++;
    }
    return 0;

}
