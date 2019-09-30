#include <stdio.h>
#include <string.h>
#define  MAXCHAR 100
void Add (char *ch1 , char *ch2 , char *ch3)
{// ch3 = ch1 + ch2;
 int len1 = strlen (ch1) , len2 = strlen (ch2) , len3 , i , tmp , num1[MAXCHAR] , num2[MAXCHAR] , num3[MAXCHAR];
 memset (num1 , 0 , sizeof(num1)); 
 memset (num2 , 0 , sizeof(num2)); 
 memset (num3 , 0 , sizeof(num3));
 
  for (i=len1-1;i>=0;i--) num1[len1-1-i] = ch1[i] - 48; for (i=len2-1;i>=0;i--) num2[len2-1-i] = ch2[i] - 48;
 i = 0 , tmp = 0 , len3 = len1 > len2 ? len1 : len2;
 while (i < len3)
 {
  num3[i] = num1[i] + num2[i] + tmp;
  tmp = 0;
  if (num3[i] >= 10) { tmp = num3[i]/10; num3[i] %= 10; }
  i ++;
 }
 if (tmp != 0) { num3[i] = tmp; i ++; }
 len3 = i;
 for (i=len3-1;i>=0;i--) ch3[len3-1-i] = num3[i] + 48;
 ch3[len3] = '\0';
 return ;
}
void Minus (char *ch1 , char *ch2 , char *ch3)
{ // 保证 ch1 > ch2 : ch3 = ch1 - ch2
 int i , tmp , len1 = strlen (ch1) , len2 = strlen (ch2) , len3 , num1[MAXCHAR] , num2[MAXCHAR] , num3[MAXCHAR];
 memset (num1 , 0 , sizeof(num1)); 
 memset (num2 , 0 , sizeof(num2));
 memset (num3 , 0 , sizeof(num3));
 for (i=0;i<len1;i++) num1[len1-1-i] = ch1[i] - 48; for (i=0;i<len2;i++) num2[len2-1-i] = ch2[i] - 48;
 i = 0 , tmp = 0 , len3 = len1 > len2 ? len1 : len2;
 while (i < len3)
 {
  num3[i] = num1[i] - num2[i] - tmp;
  if (num3[i] < 0) { num3[i] += 10 , tmp = 1; }
  else tmp = 0;
  i ++;
 }
 
 while (len3 > 1 && num3[len3-1] == 0) len3 --;
 for (i=0;i<len3;i++) ch3[i] = num3[len3-1-i] + 48;
 ch3[len3] = '\0';
 return ;
}
void MUL (char *ch1 , char *ch2 , char *ch3)
{// ch3 = ch1*ch2;
 int i , j , len1 = strlen (ch1) , len2 = strlen (ch2) , len3 , tmp , num1[MAXCHAR] , num2[MAXCHAR] , num3[MAXCHAR];
 memset (num1 , 0 , sizeof(num1)); 
 memset (num2 , 0 , sizeof(num2)); 
 memset (num3 , 0 , sizeof(num3));
 for (i=len1-1;i>=0;i--) num1[len1-1-i] = ch1[i] - 48; for (i=len2-1;i>=0;i--) num2[len2-1-i] = ch2[i] - 48;
 for (i=0;i<len1;i++)
 {
  tmp = 0;
  for (j=0;j<len2;j++)
  {
   num3[i+j] += num1[i]*num2[j] + tmp; 
   tmp = 0;
   if (num3[i+j] >= 10) { tmp = num3[i+j]/10; num3[i+j] %= 10; }
  }
  while (tmp != 0) { num3[i+j] += tmp; tmp = num3[i+j]/10; j ++; }
 }
 len3 = len1+len2;
 while (len3 > 1 && num3[len3-1] == 0) len3 --; 
 for (i=0;i<len3;i++) ch3[len3-1-i] = num3[i] + 48;
 ch3[len3] = '\0';
 return ;
}
int cmp (char *ch1 , char *ch2) 
{// ch1 > ch2 return 1;  ch1 < ch2 return -1; ch1 == ch2 return 0;
 int i , len1 = strlen (ch1) , len2 = strlen (ch2);
 if (len1 > len2) return 1;
 if (len2 > len1) return -1; 
 for (i=0;i<len1;i++)
 {
  if (ch1[i] > ch2[i]) return 1;
  if (ch1[i] < ch2[i]) return -1;
 }
 return 0;
}
void Div (char *ch1 , char *ch2 , char *ch3)
{//保证ch1>ch2 && ch2 != 0 : ch3 = ch1/ch2 , ch1 = ch1%ch2 , 需要支持函数:cmp () , Minus ();
 int i , len1 , len2 , tmp;
 char ch4[MAXCHAR] , ch5[MAXCHAR];
 ch3[0] = '0' , ch3[1] = '\0';
 while (cmp (ch1 , ch2) >= 0)
 {
  len1 = strlen (ch1) , len2 = strlen (ch2);
  tmp = len1-len2-1 > 0 ? len1-len2-1 : 0;
  
  ch4[0] = '1';
     memcpy (ch5 , ch2 , (len2+1)*sizeof(char));
  for (i=0;i<tmp;i++) { ch4[1+i] = '0' , ch5[len2+i] = '0'; } 
  ch4[1+i] = '\0'; ch5[len2+i] = '\0';
  Add (ch3 , ch4 , ch3); // ch3 += ch4;
  Minus (ch1 , ch5 , ch1); // ch1 -= ch5;
 }
 return ;
}
void Mod (char *ch1 , char *ch2)
{// 保证ch1 >= ch2 : ch1 %= ch2 , 需要支持函数:Minus () , cmp ();
 int i , len1 , len2 , tmp;
 char ch3[MAXCHAR];
 while (cmp (ch1 , ch2) >= 0)
 {
  len1 = strlen (ch1) , len2 = strlen (ch2); 
  tmp = len1-len2-1 > 0 ? len1-len2-1 : 0;
  memcpy (ch3 , ch2 , (len2+1)*sizeof(char));
  for (i=0;i<tmp;i++) ch3[len2 + i] = '0'; ch3[len2 + i] = '\0';
  Minus (ch1 , ch3 , ch1);
 }
 return ;
}
void GCD (char *ch1 , char *ch2 , char *ch3)
{//最大公约数 , ch3 = gcd(ch1 , ch2) , 需要支持函数:mod () , cmp () , Minus;
 int  len1 , len2 , tmp , flag = 1;
 while (1) {
  tmp = cmp (ch1 , ch2);
  if (tmp == 1) Mod (ch1 , ch2); 
  else if (tmp == 0) break ;
  else Mod (ch2 , ch1);
  len1 = strlen (ch1) , len2 = strlen (ch2);
  if (len1 == 1 && ch1[0] == '0') { flag = 2; break ; }
  if (len2 == 1 && ch2[0] == '0') { flag = 1; break ; }   
 }
 if (flag == 1) memcpy (ch3 , ch1 , (strlen (ch1)+1)*sizeof(char)); 
 else memcpy (ch3 , ch2 , (strlen (ch2)+1)*sizeof(char));
 return ;
}
int main ()
{
 int C,N,i,j,k,t,l,flag;
 char ch[1000][MAXCHAR],temp[MAXCHAR],g[MAXCHAR],temp2[MAXCHAR],temp3[MAXCHAR];
 FILE *in,*ou;
  if((in=fopen("B-large.in","r"))==NULL)
    {
        printf("Can not open the file");
        exit(0);
    }    
    if((ou=fopen("ou.txt","w"))==NULL)
    {
        printf("Can not open the file");
        exit(0);
    }
    fscanf(in,"%d",&C);
    for(i=0;i<C;i++)
    {
       //printf("%d",i);
       fscanf(in,"%d",&N);
       t=N;
       for(j=0;j<t;j++) 
       {
           fscanf(in,"%s",ch[j]);
           flag=0;
           for(k=0;k<j;k++) 
               if(cmp(ch[j],ch[k])==0)
               {
                   flag=1;
                   j--;
                   t--;
               }
       }
       N=t;
       for(j=0;j<N;j++)
          for(k=j+1;k<N;k++)
          {
              t=cmp(ch[j],ch[k]);
              if(t==1)
              {
                  strcpy(temp,ch[j]);
                  strcpy(ch[j],ch[k]);
                  strcpy(ch[k],temp);
              }
          }
       //for(j=0;j<N;j++) fprintf(ou,"%s ",ch[j]);
       //fprintf(ou,"\n");
       Minus(ch[1],ch[0],temp);
       //printf("%s\n",temp);
       for(j=0;j<N-2;j++)
       {   
           Minus(ch[j+2],ch[j+1],temp2);
           //printf("%s  %s",temp,temp2);
           GCD(temp,temp2,temp3);
           strcpy(temp,temp3);           
       }
       //printf("%s\n",temp);
       strcpy(temp3,ch[N-1]);
       Mod(temp3,temp);
       //printf("%s\n",temp3);
       if(cmp(temp3,"0\0")!=0) Minus(temp,temp3,temp2);
       else strcpy(temp2,"0\0");
       fprintf(ou,"Case #%d: %s\n",i+1,temp2);
    }
    
    
// while (scanf ("\n%s %s" , temp2 , temp3) != EOF)
//{
   //Mod (temp2 , temp3);
   //printf ("%s\n" , temp2);
 //}
 fclose(in);
 fclose(ou);
 getch();
 return 0; 
}
