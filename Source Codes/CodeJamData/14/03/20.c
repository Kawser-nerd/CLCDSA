#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mapa[100][100];

int main (void)
{
	int t;
	
	int r, c, m;
	
	int total;
	
	int i, j, k;
	
	FILE *fout = fopen("mine.out", "w");
	
	scanf("%d", &t);
	
	for (i = 1; i <= t; i++) {
		
		memset(mapa, 0, sizeof(char) * 100 * 100);
		
		scanf("%d %d %d", &r, &c, &m);
		
		total = r * c;
		
		fprintf(fout, "Case #%d:\n", i);
		
		
		if (total - m == 1) {
			
			for (j = 0; j < r; j++) {
				for (k = 0; k < c; k++) {
					if (!j && !k) {
						fprintf(fout, "c");
					} else {
							fprintf(fout, "*");
							total--;
					}
				}
				fprintf(fout, "\n");
			}
			
			
		} else if (r == 1 || c == 1) {
			
			for (j = 0; j < r; j++) {
				for (k = 0; k < c; k++) {
					if (total == r * c) {
						total--;
						fprintf(fout, "c");
					} else if (total > m) {
							fprintf(fout, ".");
							total--;
					} else {
							fprintf(fout, "*");
							total--;
					}
				}
				fprintf(fout, "\n");
			}
		} else if (r == 2 || c == 2) {
			if (!((total - m) % 2) && (total - m) > 3) {
				
				
				if (c == 2) {
					for (j = 0; j < r; j++) {
						for (k = 0; k < c; k++) {
							if (total == r * c) {
								total--;
								fprintf(fout, "c");
							} else if (total > m) {
									fprintf(fout, ".");
									total--;
							} else {
								fprintf(fout, "*");
								total--;
								}
						}
						fprintf(fout, "\n");
					}
				} else {
					total -= m;
					total /= 2;
					
					for (j = 0; j < r; j++) {
						for (k = 0; k < c; k++) {
							if (!j && !k) {
// 								total--;
								fprintf(fout, "c");
							} else if (k < total) {
									fprintf(fout, ".");
// 									total--;
							} else {
								fprintf(fout, "*");
// 								total--;
								}
						}
						fprintf(fout, "\n");
					}
				}
				
			} else {
				fprintf(fout, "Impossible\n");
			}
		} else {
			if ((((total - m) % 2) && (total - m) > 8) || (!((total - m) % 2) && (total - m) > 3)) {
				
				if ((total - m) % 2) {
					
					total -= m;
					
					int p = 3;
					
					mapa[0][0] = 'c';
					mapa[0][1] = '.';
					mapa[0][2] = '.';
					mapa[1][0] = '.';
					mapa[1][1] = '.';
					mapa[1][2] = '.';
					mapa[2][0] = '.';
					mapa[2][1] = '.';
					mapa[2][2] = '.';
					total -= 9;
					
					while (total) {
						
						
						if (p < r)
							total -= 2;
						
						mapa[p][0] = '.';
						mapa[p][1] = '.';
						
						p++;
						
						if (p >= r && total) {
							p = 3;
							
							while (total) {
								
								if (p < c)
									total -= 2;
								
								mapa[0][p] = '.';
								mapa[1][p] = '.';
								
								p++;
								
								if (p >= c && total) {
									p = 3;
									
// 									total--;
									while (total) {
										
										if (p < c)
											total -= 1;
										
										mapa[2][p] = '.';
// 										mapa[2][p + 1] = '.';
										
										p++;
										
										if (p >= c && total) {
											int q = 2;
											p = 3;
											
// 											total--;
											while (total) {
												
												if (p < r && q < c)
												total -= 1;
												
												mapa[p][q] = '.';
// 												mapa[p + 1][q] = '.';
												
												p++;
												
												if (p >= r && total) {
													q++;
													p = 3;
// 													total--;
												}
											}
											
										}
									}
								}
							}
						}
					}
					
				} else {
					
					
					total -= m;
					
					int p = 2;
					
					mapa[0][0] = 'c';
					mapa[0][1] = '.';
					mapa[1][0] = '.';
					mapa[1][1] = '.';
					total -= 4;
					
					while (total) {
						
						if (p < r)
							total -= 2;
						
						mapa[p][0] = '.';
						mapa[p][1] = '.';
						
						p++;
						
						if (p >= r && total) {
							int q = 2;
							p = 0;
							
// 							total--;
							while (total) {
								
								if (q < c)
								total -= 1;
								
								mapa[p][q] = '.';
// 								mapa[p + 1][q] = '.';
								
								p++;
								
								if (p >= r && total) {
									
									if (total % 2) {
										mapa[p - 1][q] = 0;
										total++;
									}
									
									
									
									q++;
									p = 0;
// 									total--;
									
									if (q >= c && total) {
										p = r - 1;
										q = c - 1;
										
										while (total) {
											mapa[p][q] = '.';
											mapa[p][q - 1] = '.';
											q -= 2;
											total -= 2;
										}
									}
								}
							}
							
						}
					}
				}
				
				
				for (j = 0; j < r; j++) {
					for (k = 0; k < c; k++) {
						if(mapa[j][k] == 0)
							fprintf(fout, "*");
						else
							fprintf(fout, "%c", mapa[j][k]);
					}
					fprintf(fout, "\n");
				}//TASK
			} else {
				fprintf(fout, "Impossible\n");
			}
		}
	}
	
	return 0;
	
}