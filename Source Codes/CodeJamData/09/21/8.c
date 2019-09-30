#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

static char *gptr=NULL;

static char *read_line(void)
{
  static FILE *ifp=NULL;
  char rv[10240+1];
  char *str;
  int len;

  if (!ifp)
    ifp=fopen("./infile","r");
  
  rv[0]=0;
  fgets(rv,10240,ifp);
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

typedef struct _nodestruct
{
  char property[20];
  double val;
  struct _nodestruct *yes;
  struct _nodestruct *no;
} nodestruct;

nodestruct *add_node(const char *prop,double val)
{
  nodestruct *rv=(nodestruct *)calloc(1,sizeof(nodestruct));
  if (prop && *prop)
    {
      strcpy(rv->property,prop);
    }
  rv->val=val;

  return rv;
}

nodestruct *build_tree()
{
  nodestruct *rv;
  char str[20];
  double val;
  int idx;

  while (isspace(*gptr))
    gptr++;
  if (*gptr=='(')
    {
      gptr++;
      //new node
      while (isspace(*gptr))
	gptr++;
      val=atof(gptr);
      while (!isspace(*gptr) && *gptr!='(' && *gptr!=')')
	gptr++;
      while (isspace(*gptr) && *gptr!='(' && *gptr!=')')
	gptr++;
      idx=0;
      while (!isspace(*gptr) && *gptr!='(' && *gptr!=')')
	{
	  str[idx++]=*gptr;
	  gptr++;
	}
      str[idx]=0;
      rv=add_node(str,val);
      while (isspace(*gptr) && *gptr!='(' && *gptr!=')')
	gptr++;

      if (*gptr == ')')
	{
	  gptr++;
	  return rv;
	}

      rv->yes=build_tree(gptr);
      rv->no=build_tree(gptr);

      while (isspace(*gptr) || *gptr==')')
	gptr++;
    }

  return rv;
}

main()
{
  char *line;
  char **ary,*treeline;
  int loopa,loopb,loopc;
  int sets,lines,idx,finished;
  double score;
  nodestruct *root,*scan;
  char **animal;
  int animals;

  line=read_line();
  sets=atoi(line);

  for (loopa=0;loopa < sets;loopa++)
    {
      line=read_line();
      
      lines=atoi(line);

      root=NULL;
      treeline=NULL;

      for (loopb=0;loopb < lines;loopb++)
	{
	  line=read_line();
	  if (treeline)
	    {
	      treeline=(char *)realloc(treeline,strlen(treeline)+strlen(line)+1);
	      strcat(treeline,line);
	    }
	  else
	    treeline=strdup(line);
	}

      //Build the tree
      gptr=treeline;
      root=build_tree();

      write_line("Case #%d:\n",loopa+1);

      line=read_line();
      lines=atoi(line);
      for (loopb=0;loopb < lines;loopb++)
	{
	  line=read_line();
	  ary=string_to_array(line,' ');

	  scan=root;
	  score=1.0;

	  while (scan)
	    {
	      score*=scan->val;
	      if (scan->property && *scan->property)
		{
		  idx=2;
		  finished=0;
		  while (ary[idx] && !finished)
		    {
		      if (!strcmp(ary[idx],scan->property))
			{
			  finished=1;
			  scan=scan->yes;
			}
		      idx++;
		    }
		  if (!finished)
		    {
		      scan=scan->no;
		    }
		}
	      else
		{
		  scan=scan->no;
		}
	    }
	  write_line("%.07f\n",score);
	}

    }

  return;
}
