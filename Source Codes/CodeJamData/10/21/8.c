#include <stdio.h>
#include <string.h>

char name_buf [100000];
int name_size;

char *alloc_name(char *name)
{
  char *ret = strcpy(name_buf + name_size, name);

  name_size += strlen(name) + 1;

  return ret;
}

typedef struct node
{
  char *name;
  struct node *next;
  struct node *sub;
} node_t;

node_t node_buf [100000];
int node_size;

node_t *alloc_node(char *name, node_t *next, node_t *sub)
{
  node_t *curr = &node_buf [node_size++];

  curr->name = alloc_name (name);
  curr->next = next;
  curr->sub = sub;

  return curr;
}

void reset_nodes()
{
  node_size = 1;
  name_size = 0;
  node_buf->next = node_buf->sub = 0;
  node_buf->name = "/";
}

int create_path(char *path)
{
  node_t *i;
  char *s;
  int sum;

  i = node_buf;
  s = strtok (path, "/");
  sum = 0;

  while (s)
    {
#ifdef DEBUG
      fprintf (stderr, "s = %s\r\n", s);
      fprintf (stderr, "i = %s\r\n", i->name);
#endif

      if (i->sub)
	{
	  i = i->sub;

	  while (1)
	    {
#ifdef DEBUG
	      fprintf (stderr, "  i = %s\r\n", i->name);
#endif
	      
	      if (!strcmp(i->name, s))
		  break;
	      else if (!i->next)
		{
		  i->next = alloc_node(s, 0, 0);
		  i = i->next;
		  sum++;

		  break;
		}
	      else
		i = i->next;
	    }
	}
      else
	{
	  i->sub = alloc_node(s, 0, 0);
	  i = i->sub;
	  sum++;
	}
      
      s = strtok(0, "/");
    }

  return sum;
}

char buf [101];

int main()
{
  int T, t;

  scanf ("%d", &T);

  for (t = 1; t <= T; t++)
    {
      int N, M;

      int sum = 0;

      reset_nodes();

      scanf ("%d %d", &N, &M);

      while (N--)
	{
	  scanf ("%s", buf);

	  create_path(buf);
	}

      while (M--)
	{
	  scanf ("%s", buf);

	  sum += create_path(buf);
	}

      printf ("Case #%d: %d\r\n", t, sum);
    }

  return 1;
}
