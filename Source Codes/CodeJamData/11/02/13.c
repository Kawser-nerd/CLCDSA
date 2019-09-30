#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){
  FILE *f;
  if(!(f = fopen(argv[1], "r"))){ perror("FILE-RELATED OOPS"); exit(-1);}
  fseek(f, 0L, SEEK_END);
  int size = ftell(f);
  char *data = (char *)malloc(size);
  fseek(f, 0L, SEEK_SET);
  fread(data, size, 1, f);
  int i,j,k;
  for(i = 0; i < size; i++)  if(data[i] == '\n' || data[i] == ' ') data[i] = 0;
  
  char *p = data;
  int rounds = atoi(p);
  p += strlen(p)+1;
  for(i = 0; i < rounds; i++){
    int deadly[26];//How many indices are saying I am deadly?
    char combos[26][26];
    char annihilators[26][26];
    for(k = 0; k < 26; k++) deadly[k] = 0;
    for(k = 0; k < 26*26; k++){ combos[k/26][k%26] = ' ';  annihilators[k/26][k%26] = ' ';}

    int C = atoi(p);
    p += strlen(p)+1;
    for(j = 0; j < C; j++){
      combos[*(p+1) - 'A'][*p - 'A'] = *(p+2);
      combos[*p - 'A'][*(p+1) - 'A'] = *(p+2);
      p += 4;
    }
    
    int D = atoi(p);
    p += strlen(p)+1;
    for(j = 0; j < D; j++){
      annihilators[*(p+1) - 'A'][*p - 'A'] = 'd';
      annihilators[*p - 'A'][*(p+1) - 'A'] = 'd';
      p += 3;
    }
    
    int invocations = atoi(p);
    p += strlen(p)+1;
    char *spell = (char *)(malloc(invocations));
    for(j = 0; j < invocations; j++) spell[j] = *(p++);
    p++;

    char *end_list = (char *)(malloc(invocations));
    bzero(end_list, invocations);
    int len = 0;

    for(j = 0; j < invocations; j++){
      char res = (len > 0 ? combos[spell[j] - 'A'][end_list[len - 1] - 'A'] : -1);
      if(len > 0 && res >= 'A' && res <= 'Z'){//We combine with the previous thing to form res
	for(k = 0; k < 26; k++) if(annihilators[end_list[len - 1] - 'A'][k] == 'd') deadly[k]--;
	end_list[len-1] = res;
      }
      else if(deadly[spell[j] - 'A'] > 0){
	for(k = 0; k < 26; k++) deadly[k] = 0;//Nothing is deadly anymore
	len = 0;//Nothing left
	if(j >= invocations - 1) break;//We're done and have an empty list
      }
      else{//We didn't cancel or combine
	for(k = 0; k < 26; k++) if(annihilators[spell[j] - 'A'][k] == 'd') deadly[k]++;//Some things are more deadly now...
	end_list[len++] = spell[j];//Put us on the end
      }
    }
  
    //Now to print: 

    printf("Case #%d: [", i+1);
    if(len > 0){
      for(k = 0; k < len-1; k++) printf("%c, ", end_list[k]);
      printf("%c]\n", end_list[len - 1]);
    }
    else printf("]\n");
    free(spell);
    free(end_list);
  }
  free(data);
}
