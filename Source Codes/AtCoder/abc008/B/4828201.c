#include <stdio.h>
#include <string.h>

int main() {
  int number_of_member, member_i, member_j, top_candidate, max_votes = 0;
  scanf("%d", &number_of_member);
  char vote_list[number_of_member][51];
  int counter[number_of_member];

  for(member_i = 0; member_i < number_of_member; member_i++) {
    scanf("%s", vote_list[member_i]);
    counter[member_i] = 0;
  }

  for(member_i = 0; member_i < number_of_member; member_i++) {
    for(member_j = member_i; member_j < number_of_member; member_j++) {
      if(strcmp(vote_list[member_i], vote_list[member_j]) == 0) {
        counter[member_i]++;
      }
    }
  }

  for(member_i = 0; member_i < number_of_member; member_i++) {
    if(counter[member_i] > max_votes) {
      max_votes = counter[member_i];
      top_candidate = member_i;
    }
  }

  printf("%s\n", vote_list[top_candidate]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &number_of_member);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", vote_list[member_i]);
     ^