#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sgn(int x){
  return (x > 0 ? 1 : (x != 0 ? -1 : 0));
}

int abs(int x){
  return x*sgn(x);
}

int main(int argc, char **argv){
  FILE *f;
  if(!(f = fopen(argv[1], "r"))){ perror("FILE-RELATED OOPS"); exit(-1);}
  fseek(f, 0L, SEEK_END);
  int size = ftell(f);
  char *data = (char *)malloc(size);
  fseek(f, 0L, SEEK_SET);
  fread(data, size, 1, f);
  int i,j;
  for(i = 0; i < size; i++)  if(data[i] == '\n' || data[i] == ' ') data[i] = 0;
  
  char *p = data;
  int rounds = atoi(p);
  p += strlen(p)+1;
  for(i = 0; i < rounds; i++){
    int buttons = atoi(p), answer = 0, current_len = 0, current_index = 0, current_len_index = 0, num_lists = 1;
    p += strlen(p)+1;
    char current_guy = *p;
    int *lists = (int *)(malloc(sizeof(int)*buttons));
    int *list_lens = (int *)(malloc(sizeof(int)*buttons));
    for(j = 0; j < buttons; j++){
      if(*p != current_guy){
	current_guy = *p;
	list_lens[current_len_index++] = current_len;
	current_len = 0;
	num_lists++;
      }
      p += 2;
      lists[current_index++] = atoi(p);
      p += strlen(p)+1;
      current_len++;
    }
    list_lens[current_len_index] = current_len;

    /*
      This is the loop during which X is travelling along its buttons next while
      Y is travelling to the start of its list, where X and Y alternate between
      B and O.
    */
    int current_list = 0, Xstart = 1, Ystart = 1, Xlistlen = list_lens[current_list], Ygo = lists[list_lens[current_list]], Xloc = 1, Yloc = 1;
    int* Xlist = lists;
    
    while(current_list < num_lists){
      int Ytime = abs(Ygo - Ystart);
      int Xtime = abs(Xlist[0] - Xstart) + 1;
      for(j = 1; j < Xlistlen; j++) Xtime += abs(Xlist[j] - Xlist[j-1]) + 1;
      answer += Xtime;
      if(current_list >= num_lists - 1) break;
      Xloc = Xlist[Xlistlen-1];
      Yloc = (Ytime > Xtime ? Ystart + sgn(Ygo - Ystart)*Xtime : Ygo);
      Xstart = Yloc;
      Ystart = Xloc;
      Xlist += Xlistlen;
      Xlistlen = list_lens[++current_list];
      Ygo = Xlist[Xlistlen];

    }

    printf("Case #%d: %d\n", i+1, answer);
  }
}
