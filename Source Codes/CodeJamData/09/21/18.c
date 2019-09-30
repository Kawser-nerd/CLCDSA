#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct _trie_node {
  struct _trie_node* le;
  struct _trie_node* eq;
  struct _trie_node* gt;
  char c;
} trie_node;

trie_node*
trie_add(trie_node* n, char* s) {
  if(n == 0) {
    n = (trie_node*)malloc(sizeof(trie_node));
    n->c = *s;
    n->le = 0;
    n->eq = 0;
    n->gt = 0;
  }

  if(*s == n->c) {
    if(*s != 0) {
      n->eq = trie_add(n->eq, s+1);
    }
  } else if(*s > n->c) {
    n->gt = trie_add(n->gt, s);
  } else {
    n->le = trie_add(n->le, s);
  }

  return n;
}

void
trie_delete(trie_node* n) {
  if(n != 0) {
    trie_delete(n->le);
    trie_delete(n->eq);
    trie_delete(n->gt);

    free(n);
  }
}

int
trie_search(trie_node* n, char* s) {
  int result = 0;

  if(n != 0) {
    if(*s == n->c) {
      if(*s != 0) {
        result = trie_search(n->eq, ++s);
      } else {
        result = 1;
      }
    } else if(*s > n->c) {
      result = trie_search(n->gt, s);
    } else {
      result = trie_search(n->le, s);
    }
  }

  return result;
}

typedef struct _node {
  double weight;
  char* feature;
  struct _node* first;
  struct _node* second;
} node;

char*
parse_tree(char* in, node** result) {
  char* c = in;
  
  while(isspace(*c)) c++;
  if(*c == '(') {
    c++;
    while(isspace(*c)) c++;
    *result = (node*)malloc(sizeof(node));
    
    (*result)->weight = 0;
    (*result)->feature = 0;
    (*result)->first = 0;
    (*result)->second = 0;
    
    sscanf(c, "%lf", &((*result)->weight));
     
    while((*c == '.') || isdigit(*c)) c++;
    while(isspace(*c)) c++;
    
    if(isalpha(*c)) {
      (*result)->feature = c;
      while(isalpha(*c)) c++;
      *c = 0;
      c++;
      c = parse_tree(c, &((*result)->first));
      c = parse_tree(c, &((*result)->second));
      while(isspace(*c)) c++;
      c++; /* skip ')' */
    } else {
      while(isspace(*c)) c++;
      c++; /* skip ')' */
    }
  } else {
    *result = 0;
    c++;
  }
  
  return c;
}

void
delete_tree(node* n) {
  if(n != 0) {
    delete_tree(n->first);
    delete_tree(n->second);
    free(n);
  }
}

double
cute(node* d, trie_node* f) {
  double result = 1;
  
  while((d != 0) && (d->feature != 0)) {    
    result *= d->weight;
    if(trie_search(f, d->feature)) {
      d = d->first;
    } else {
      d = d->second;
    }
  }
  
  if(d != 0) {
    result *= d->weight;
  }
    
  return result;
}

int
main() {
  int n;
  int c;
  
  scanf("%d\n", &n);
  
  for(c = 1; c <= n; c++) {
    char buf[1024] = "";
    int l;
    int a;
    int i;
    node* root;
    
    scanf("%d\n", &l);
    
    for(i = 0; i < l; i++) {
      char line[81] = "";
      
      fgets(line, 80, stdin); /*will read '\n' in*/
      strcat(buf, line);
    }
    
    parse_tree(buf, &root);
    
    scanf("%d\n", &a);
    
    printf("Case #%d:\n", c);
    for(i = 0; i < a; i++) {
      int nf;
      int f;
      trie_node* features = 0;
      
      scanf("%*s %d", &nf);
      for(f = 0; f < nf; f++) {
        char feature[11];
        scanf("%s", feature);
        
        features = trie_add(features, feature);
      }
      
      printf("%f\n", cute(root, features));
      
      trie_delete(features);
    }
    
    delete_tree(root);
  }
  
  return 0;
}
