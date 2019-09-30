#include "stdio.h"

int main ()
{
	int t,i;
	scanf("%d", &t);

	for (i=0; i<t; i++) {
		int wall[301] = {0};
		
		int N,j;
		int tribe[10][8] = {{0}};
		scanf("%d", &N);
		for (j=0; j<N; j++) {
			int k;
			for(k=0; k<8; k++) {
				scanf("%d", &(tribe[j][k]));
			}

			tribe[j][2] += 100;
			tribe[j][3] += 100;
		}

		int day = 0;
		int n_success_attack = 0;	
		while(1) {
	
			int k;
			int all_attack_finish = 1;
			int max_wall_damage[301] = {0};
			for (j=0; j<N; j++) {
				
				if(tribe[j][1]) {
					all_attack_finish = 0;
				}else{
					continue;
				}

				if ((day < tribe[j][0]) || ((day - tribe[j][0]) % tribe[j][5])) {
					// not attack day;
					continue;
				}
		
//				printf(">>day:%d tribe %d, [%d,%d] s:%d ",day,  j, tribe[j][2]-100, tribe[j][3]-100, tribe[j][4]);

				int is_attack_success = 0;

				{
					int pos;
					for (pos = tribe[j][2]; pos < tribe[j][3]; pos++) {
						if (wall[pos] < tribe[j][4]) {
							is_attack_success = 1;
							if (tribe[j][4] > max_wall_damage[pos])
								max_wall_damage[pos] = tribe[j][4];
						}
						
//						printf("[pos:%d wall:%d %s] ", pos-100, wall[pos], (wall[pos]<tribe[j][4])?"S":"F");
					}
				}

//				printf("\n");

				if (is_attack_success) {
					n_success_attack++;
				}
				
				// update tribe data
				tribe[j][2] += tribe[j][6];
				tribe[j][3] += tribe[j][6];
				tribe[j][4] += tribe[j][7];
				tribe[j][1]--;
			} 

			if (all_attack_finish) {
				break;
			}
			
			// update wall
			for (k=0; k<301; k++) {
				if (max_wall_damage[k]) {
					wall[k] = max_wall_damage[k];
				}
			}

			day++;
		}
	
		printf("Case #%d: %d\n", i+1, n_success_attack);
	}
	return 0;
}
