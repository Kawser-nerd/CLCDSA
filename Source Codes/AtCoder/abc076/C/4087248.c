#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//char str_1[100002],str_2[100002];
int cmp(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
    int len_1,len_2,i,j,count,k,flag,n;//count????????
    char str_T[101],str_S[101],result[101][101];
    scanf("%s",str_S);
    scanf("%s",str_T);
    count=0;
    flag=n=0;
    len_1=strlen(str_S);
    len_2=strlen(str_T);
    if(len_1<len_2)
    {
        printf("UNRESTORABLE\n");
        return 0;
    }
    else
    {
        for(i=len_1-1; i>=0; i--)
        {
            /*if(str_S[i]=='?')
                count++;
            else count=0;
            if(count==len_2)
            {
                strcpy(result[n],str_S);
                for(j=i,k=0; j<len_1; j++)
                {
                    result[n][j]=str_T[k];
                    k++;
                }
                for(j=0; j<len_1; j++)
                {
                    if(result[n][j]=='?')
                        result[n][j]='a';
                }
                n++;
                flag=1;
            }*/
            if(str_S[i]=='?'||str_S[i]==str_T[len_2-1])
            {
                k=i;
                for(j=len_2-1; j>=0; j--)
                {
                    if(str_T[j]==str_S[k]||str_S[k]=='?')
                    {
                        k--;
                    }
                    else
                    {
                        break;
                    }
                }
                if(k==i-len_2)
                {
                    k=i;
                    strcpy(result[n],str_S);
                    for(j=len_2-1; j>=0; j--,k--)
                    {
                        result[n][k]=str_T[j];
                    }
                    for(j=0; j<len_1; j++)
                    {
                        if(result[n][j]=='?')
                            result[n][j]='a';
                    }
                    flag=1;
                    n++;
                }
            }
        }
    }
    if(flag==1)
    {
        qsort(result,n,101*sizeof(char),cmp);
        printf("%s\n",result[0]);
    }
    else printf("UNRESTORABLE\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",str_S);
     ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",str_T);
     ^