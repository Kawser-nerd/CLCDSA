#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N, i;
  int ans = 0;

  scanf("%d", &N);

  char w[N][1024];

  int len[N];

  for(i = 0; i < N; i++){
    scanf("%s", w[i]);
    len[i] = strlen(w[i]);
    if(i != N - 1){
      if(len[i] == 12){
	if(w[i][0] == 'T'){
	  if(w[i][1] == 'A'){
	    if(w[i][2] == 'K'){
	      if(w[i][3] == 'A'){
		if(w[i][4] == 'H'){
		  if(w[i][5] == 'A'){
		    if(w[i][6] == 'S'){
		      if(w[i][7] == 'H'){
			if(w[i][8] == 'I'){
			  if(w[i][9] == 'K'){
			    if(w[i][10] == 'U'){
			      if(w[i][11] == 'N'){
				ans++;
			      }}}}}}}}}}}}
	if(w[i][0] == 'T'){
	  if(w[i][1] == 'a'){
	    if(w[i][2] == 'k'){
	      if(w[i][3] == 'a'){
		if(w[i][4] == 'h'){
		  if(w[i][5] == 'a'){
		    if(w[i][6] == 's'){
		      if(w[i][7] == 'h'){
			if(w[i][8] == 'i'){
			  if(w[i][9] == 'k'){
			    if(w[i][10] == 'u'){
			      if(w[i][11] == 'n'){
				ans++;
			      }}}}}}}}}}}}
	if(w[i][0] == 't'){
	  if(w[i][1] == 'a'){
	    if(w[i][2] == 'k'){
	      if(w[i][3] == 'a'){
		if(w[i][4] == 'h'){
		  if(w[i][5] == 'a'){
		    if(w[i][6] == 's'){
		      if(w[i][7] == 'h'){
			if(w[i][8] == 'i'){
			  if(w[i][9] == 'k'){
			    if(w[i][10] == 'u'){
			      if(w[i][11] == 'n'){
				ans++;
			      }}}}}}}}}}}}
      }
    }else{
      if(len[i] == 13){
	if(w[i][0] == 'T'){
	  if(w[i][1] == 'A'){
	    if(w[i][2] == 'K'){
	      if(w[i][3] == 'A'){
		if(w[i][4] == 'H'){
		  if(w[i][5] == 'A'){
		    if(w[i][6] == 'S'){
		      if(w[i][7] == 'H'){
			if(w[i][8] == 'I'){
			  if(w[i][9] == 'K'){
			    if(w[i][10] == 'U'){
			      if(w[i][11] == 'N'){
				ans++;
			      }}}}}}}}}}}}
	if(w[i][0] == 'T'){
	  if(w[i][1] == 'a'){
	    if(w[i][2] == 'k'){
	      if(w[i][3] == 'a'){
		if(w[i][4] == 'h'){
		  if(w[i][5] == 'a'){
		    if(w[i][6] == 's'){
		      if(w[i][7] == 'h'){
			if(w[i][8] == 'i'){
			  if(w[i][9] == 'k'){
			    if(w[i][10] == 'u'){
			      if(w[i][11] == 'n'){
				ans++;
			      }}}}}}}}}}}}
	if(w[i][0] == 't'){
	  if(w[i][1] == 'a'){
	    if(w[i][2] == 'k'){
	      if(w[i][3] == 'a'){
		if(w[i][4] == 'h'){
		  if(w[i][5] == 'a'){
		    if(w[i][6] == 's'){
		      if(w[i][7] == 'h'){
			if(w[i][8] == 'i'){
			  if(w[i][9] == 'k'){
			    if(w[i][10] == 'u'){
			      if(w[i][11] == 'n'){
				ans++;
			      }}}}}}}}}}}}
      }
    }
  }

  printf("%d\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", w[i]);
     ^