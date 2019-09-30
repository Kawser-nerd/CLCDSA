#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inputline[100];
int a,b,N;
int alice,borys;

int main(){

	alice = 0;
	borys = 0;

	fgets(inputline,sizeof(inputline),stdin);
	sscanf(inputline,"%d %d %d",&N,&a,&b);

	alice = a;
	borys = b;

	for(int i=0;i<100;i++){

		if(alice + 1  !=  borys){

			alice = alice + 1;

		}
		
		else if(alice + 1 == borys){

			if(alice == 0){

				printf("Borys\n");

				return 0;

			}

			alice = alice -1;

		}

		if(borys - 1 != alice){

			borys = borys - 1;

		}

		else if(borys - 1 == alice){

			if(borys == N){
				printf("Alice\n");

				return 0;
			}

			borys = borys + 1;

		}

	}
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(inputline,sizeof(inputline),stdin);
  ^