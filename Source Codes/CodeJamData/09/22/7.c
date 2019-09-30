#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static char *read_line(void)
{
  static FILE *ifp=NULL;
  char rv[1024+1];
  char *str;
  int len;

  if (!ifp)
    ifp=fopen("./infile","r");
  
  rv[0]=0;
  fgets(rv,1024,ifp);
  len=strlen(rv);

  while (len>0 && strchr("\n\r",rv[len-1]))
    rv[--len]=0;

  if (len<1)
    return NULL;

  str=(char *)malloc(len+1);
  strcpy(str,rv);
  return str;
}

static void write_line(const char *fmt,...)
{
  static FILE *ofp=NULL;
  va_list varlist;

  if (!ofp)
    ofp=fopen("./outfile","w");

  va_start(varlist,fmt);
  vfprintf(ofp,fmt,varlist);
  va_end(varlist);

  fflush(ofp);

  va_start(varlist,fmt);
  vprintf(fmt,varlist);
  va_end(varlist);

  fflush(stdout);
}

char **string_to_array(const char *str,char delim)
{
  char *ptr,*start;
  int count;
  char **rv;

  if (*str)
    count=1;
  else
    return NULL;

  ptr=strdup(str);
  start=ptr;
  while (ptr && *ptr)
    {
      if (*ptr==delim && *(ptr+1))
	count++;
      ptr++;
    }    

  rv=(char **)malloc((count+1)*sizeof(char *));

  count=0;
  ptr=start;
  rv[0]=ptr;

  while (ptr && *ptr)
    {
      if (*ptr==delim && *(ptr+1))
	{
	  *ptr=0;
	  count++;
	  ptr++;
	  rv[count]=ptr;
	}
      else
	ptr++;
    }    

  rv[count+1]=0;

  return rv;
}

int sortit(const void *a,const void *b)
{
  int ai,bi;
  
  ai=*((int *)a);
  bi=*((int *)b);

  if (ai<bi)
    return -1;
  if (ai>bi)
    return 1;
  return 0;
}

main()
{
  char *line;
  char **ary,*ptr;
  int loopa,loopb,loopc;
  int sets;
  int next[100];
  int last[100];
  int available[100];
  int digits,count,idx,finished,lowidx,trans;

  line=read_line();
  sets=atoi(line);

  for (loopa=0;loopa < sets;loopa++)
    {
      line=read_line();

      ptr=line;
      digits=0;
      while (*ptr)
	{
	  last[digits]=*ptr-48;
	  digits++;
	  ptr++;
	}
      
      idx=digits-1;

      finished=0;
      while (!finished)
	{
	  while (!finished && idx>0)
	    {
	      idx--;
	      if (last[idx] < last[idx+1])
		{
		  finished=1;
		  //This is the one to swap, now find the lowest
		  lowidx=idx+1;
		  for (loopb=idx+2;loopb < digits;loopb++)
		    {
		      if (last[loopb] > last[idx] && last [loopb] < last[lowidx])
			{
			  lowidx=loopb;
			}
		    }
		  trans=last[lowidx];
		  last[lowidx]=last[idx];
		  last[idx]=trans;
		  
		  //Now arrange the rest into lowest to highest, just bubble
		  idx++;
		  for (loopb=idx;loopb < digits;loopb++)
		    {
		      next[loopb-idx]=last[loopb];
		    }
		  qsort(next,digits-idx,sizeof(int),
			sortit);
		  
		  for (loopb=idx;loopb < digits;loopb++)
		    {
		      last[loopb]=next[loopb-idx];
		    }
		}
	    }
	  if (!finished)
	    {
	      //Add a 0 at the start maybe?
	      for (loopb=digits-1;loopb >=0;loopb--)
		{
		  last[loopb+1]=last[loopb];
		}
	      last[0]=0;
	      digits++;
	      idx=digits-1;
	    }
	}

      
      write_line("Case #%d: ",loopa+1);
      for (loopb=0;loopb < digits;loopb++)
	{
	  write_line("%d",last[loopb]);
	}
      write_line("\n");
    }

  return;
}
