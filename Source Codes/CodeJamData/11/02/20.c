#include<stdio.h>
#include<string.h>

#define MAX_N 100
#define NO_CHAR 'Z'+1



void
print_array(char * element_list, int nElements)
{
  short iElement;

  printf("[");
  for(iElement=0; iElement<nElements-1; ++iElement) {
    printf("%c, ", element_list[iElement]);
  }
  printf("%c]", element_list[nElements-1]);
}



inline
short
hash(char x, char y)
{
  return (x-'A')*26 + (y-'A');
}


int
main(void)
{
  short T, iT;
  short C, iC;
  short D, iD;
  short N, iN;

  char element_list[MAX_N];
  short nElements;
  char combine_rules[676]; // slightly more than needed; if x<y, then combine_rules[(x-'A')*26 + (y-'B')] = what x,y combines to (NO_CHAR for "they don't combine")
  char combination[4];
  int opposed_rules[26]; // only indices 'Q', 'W', 'E', 'R', 'A' (0), 'S', 'D', & 'F' are actually used; usage (e.g.): opposed_rules['Q'] is a bit string whose lowest 8 bits are, respectively, 1 if Q, W, E, R, A, S, D, F (lowest bit) showing up would cause erasure (due to being "opposed" to 'Q')
  char opposed[3];
  short cur_bad_list; // the lowest 8 bits are, respectively, 1 if Q, W, E, R, A, S, D, F (lowest bit) showing up would cause erasure (due to "opposed" elements)

  int mask[26] = {8/*'A'*/, 0, 0, 2/*'D'*/, 32/*'E'*/, 1 /*'F'*/, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128/*'Q'*/, 16/*'R'*/, 4/*'S'*/, 0, 0, 0, 64/*'W'*/, 0, 0, 0 };

  char invoke_list[MAX_N];
  char cur_element;
  char combine_output;

  char swap_temp;


  scanf("%d", &T);

  for(iT = 1; iT <= T; ++iT) {
printf("DEBUG: T: %d, iT:%d\n", T, iT);
    memset(combine_rules, NO_CHAR, 676);
    scanf("%d", &C);

    for(iC = 1; iC <= C; ++iC) {
      scanf("%s", combination);
      if(combination[0] < combination[1]) { // make combination[0] < combination[1], swapping if necessary
        swap_temp = combination[1];
        combination[1] = combination[0];
        combination[0] = swap_temp;
      }
      combine_rules[hash(combination[0], combination[1])] = combination[2];
    }


    memset(opposed_rules, 0, 26);
    scanf("%d", &D);

    for(iD = 1; iD <= D; ++iD) {
      scanf("%s", opposed);
      opposed_rules[opposed[0]] &= mask[opposed[1]];
      opposed_rules[opposed[1]] &= mask[opposed[0]];
    }


    cur_bad_list = 0;
    scanf("%d", &N);

    scanf("%s", invoke_list);
    nElements = 0;
    for(iN = 1; iN <= N; ++iN) {
printf("DEBUG: T: %d, iT:%d\n", T, iT);
      cur_element = invoke_list[iN-1];

      if(0 == nElements) { // if this is first element, no combining or opposing will happen
/* printf("DEBUG: nElements: %d; inserting %c\n", nElements, cur_element); */
        element_list[0] = cur_element;
        ++nElements;
      } else {
        combine_output = combine_rules[hash(element_list[nElements-1], cur_element)];
        if(NO_CHAR != combine_output) { // a combination now happens
          element_list[nElements-1] = combine_output; // replace last element in list with result of combining (it with the just-read element)
        } else {
          if(0 != mask[cur_element] & cur_bad_list) { // opposition (and, thus, erasure) occurs
            nElements = 0;
            cur_bad_list = 0;
          } else {
/* printf("DEBUG: nElements: %d; inserting %c\n", nElements, cur_element); */
            element_list[nElements] = cur_element;
            ++nElements;
            cur_bad_list &= mask[cur_element]; // maintain cur_bad_list
          }
        }
      }
    }

    printf("Case #%d: ", iT);
    print_array(element_list, nElements);
    printf("\n");

printf("DEBUG: T: %d, iT:%d\n", T, iT);
  }

  return(0);
}
