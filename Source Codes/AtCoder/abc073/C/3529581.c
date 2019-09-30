#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node{
  long long item;
  struct node *left;
  struct node *right;
} Node;

static Node *make_node(long long x){
  Node *node = malloc(sizeof(Node));
  if (node != NULL) {
    node->item = x;
    node->left = NULL;
    node->right = NULL;
  }
  return node;
}

static long long search_node(long long x, Node *node)
{
  long long k = 0;
  while (node != NULL) {
    if (node->item == x){
      k = 1;
      return k;
    }else if (x < node->item){
      node = node->left;
    }else{
      node = node->right;
    }
  }
  return k;
}

static Node *insert_node(long long x, Node *node){
  if (node == NULL){
    return make_node(x);
  }else if (x < node->item){
    node->left = insert_node(x, node->left);
  }else if (x > node->item){
    node->right = insert_node(x, node->right);
  }
  return node;
}

static long long search_min(Node *node)
{
  while (node->left != NULL) {
    node = node->left;
  }
  return node->item;
}

static Node *delete_min(Node *node)
{
  if (node->left == NULL) {
    Node *temp = node->right;
    free(node);
    return temp;
  }
  node->left = delete_min(node->left);
  return node;
}

static Node *delete_node(long long x, Node *node)
{
  if (node == NULL) {
    return NULL;
  }
  if (x == node->item) {
    if (node->left == NULL) {
      Node *temp = node->right;
      free(node);
      return temp;
    }
    if (node->right == NULL) {
      Node *temp = node->left;
      free(node);
      return temp;
    }
    node->item = search_min(node->right);
    node->right = delete_min(node->right);
  } else if (x < node->item){
    node->left = delete_node(x, node->left);
  }else{
    node->right = delete_node(x, node->right);
  }
  return node;
}

typedef struct {
  Node *root;
} Tree;

Tree *make_tree(void){
  Tree *tree = malloc(sizeof(Tree));
  if (tree != NULL) {
    tree->root = NULL;
  }
  return tree;
}

bool search_tree(long long x, Tree *tree){
  return search_node(x, tree->root);
}

void insert_tree(long x, Tree *tree){
  tree->root = insert_node(x, tree->root);
}

void delete_tree(long long x, Tree *tree)
{
  tree->root = delete_node(x, tree->root);
}

int main(void){
  
  long long N;
  long long i;
  long long count = 0;
  Tree *tree = make_tree();

  scanf("%lld", &N);

  long long A[N];

  for(i = 0; i < N; i++){
    scanf("%lld", &A[i]);
    if(search_tree(A[i], tree) == 1){
      count--;
      delete_tree(A[i], tree);
    }else{
      count++;
      insert_tree(A[i], tree);
    }
  }

  printf("%lld\n", count);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:127:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &N);
   ^
./Main.c:132:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &A[i]);
     ^