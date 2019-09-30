#include<stdio.h>

int main(void)
{
  char str[301],kind[301][301],temp[301];
  int len,i=0,j,k,counter=0,str_len,frag=1;
  scanf("%s",str);
  scanf("%d",&len);
  while(str[i] != '\0') //??????????
    {
      str_len++;
      i++;
    }
  
  if(str_len < len) //???????????????
    {
      printf("0\n");
      return 0;
    }

  str_len = str_len - len;
  
  for(i=0;i<=str_len;i++)
    {
      for(j=i;j<len+i;j++) //??????????
	{
	  temp[j-i] = str[j];
	}
      
      if(counter == 0) 
	{
	  for(j=0;j<len;j++)
	    {
	      kind[counter][j] = temp[j];
	    }
	  //debug
	  //printf("%s 0\n",kind[counter]); 
	  counter++;
	}
      else
	{
	  for(j=0;j<counter;j++)
	    {
	      frag = 1;
	      for(k=0;k<len;k++)
		{
		  if(kind[j][k] != temp[k])
		    {
		      frag = 0;
		      break;
		    }
		}
	      if(frag == 1)
		{
		  break;
		}
	      if(j == counter-1)
		{
		  for(k=0;k<len;k++)
		    {
		      kind[counter][k] = temp[k];
		    }
		  //debug
		  //printf("%s\n",kind[counter]); 
		  counter++;
		  break;
		}
	    }
	}
    }
  printf("%d\n",counter);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&len);
   ^