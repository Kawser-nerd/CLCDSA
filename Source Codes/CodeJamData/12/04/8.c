#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>

typedef struct ST_CONTACT{
	double distance;
	double cood[2];	
	int border;
	
	int from_ROOM_ii;
	int from_ROOM_jj;
	int to_ROOM_ii;
	int to_ROOM_jj;
}ST_CONTACT;

typedef struct ST_CONTACT_array{
	int num;
	ST_CONTACT contact[101];
}ST_CONTACT_array;

void GenerateFilename(char* out, char* in, char* add){
	char* p;
	sprintf(out, "%s", in);
	for(p=out+strlen(out)-1; p>=out; p--){
		if(*p=='/' )break;
		if(*p=='\\')break;
		if(*p=='.' ){*p='\0'; break;}
	}
	sprintf(out+strlen(out), "%s", add);
}

int ST_CONTACT_sort(const void* data1, const void* data2){
	ST_CONTACT* contact1 = (ST_CONTACT*)data1;
	ST_CONTACT* contact2 = (ST_CONTACT*)data2;

	if(contact1->distance < contact2->distance) return -1;
	if(contact1->distance > contact2->distance) return 1;
	return 0;
}

void main(int argc, char* argv[]){
	char fname_o[_MAX_PATH];
	FILE* fp_i;
	FILE* fp_o;
	int T;
	int H;
	int W;
	int D;
	int No;
	int ii;
	int jj;
	int ROOM[30][30];
	int NGSIGHT[101][101];
	int RXi;
	int RXj;
	char buff[100];
	int sum;
	int dd;
	int kk;
	int Rii;
	int Rjj;
	int Sii;
	int Sjj;
	double di;
	double dj;
	int fi;
	int fj;
	double EPS = 0.00000000000001;
	int MAX_D = 50;
	int contact_num;
	ST_CONTACT contact[200];
	ST_CONTACT* contact_p;
	int horizontal;
	int vertical;
	int corner;
	int sum_f;
	int tmp_i;
	int tmp_j;
	double tmp_di;
	double tmp_dj;
	double tmp_d;
	int a;
	int b;

	GenerateFilename(fname_o, argv[1], "_out.txt");
	fp_i = fopen(argv[1], "r");
	fp_o = fopen(fname_o, "w");

	fscanf(fp_i, "%d", &T);
	for(No=1; No<=T; No++){
		fscanf(fp_i, "%d", &H);
		fscanf(fp_i, "%d", &W);
		fscanf(fp_i, "%d", &D);

		for(ii=0; ii<H; ii++){
			fscanf(fp_i, "%s", buff);
			for(jj=0; jj<W; jj++){
				switch(buff[jj]){
				case '#':
					ROOM[ii][jj] = 0;
					break;
				case '.':
					ROOM[ii][jj] = 1;
					break;
				case 'X':
					ROOM[ii][jj] = 2;
					RXi = ii;
					RXj = jj;
					break;
				}
			}
		}
		/* Since light does not travel through you, looking directly up only shows you one image of yourself. */
		for(ii=-D; ii<=D; ii++){
			for(jj=-D; jj<=D; jj++){
				NGSIGHT[D+ii][D+jj] = 0;
			}
		}

		sum = 0;
		for(dd=1; dd<=D; dd++){
			for(ii=-dd; ii<=dd; ii++){
				for(jj=-dd; jj<=dd; jj++){
					if(abs(ii)!=dd && abs(jj)!=dd) continue;
					if(NGSIGHT[D+ii][D+jj]==1) continue;
					if(ii*ii+jj*jj>D*D) continue;

					/* set contact */
					contact_p = contact;

					/* contact with horizontal */
					if(ii!=0){
						di=(double)ii/(double)abs(ii);
						dj=(double)jj/(double)abs(ii);
						contact_p->cood[0] = di*0.5;
						contact_p->cood[1] = dj*0.5;
						contact_p->distance = sqrt(pow(contact_p->cood[0], 2.0) + pow(contact_p->cood[1] , 2.0));
						contact_p->border = 1;
						contact_num++;
						contact_p++;
						for(kk=1; kk<abs(ii); kk++){
							contact_p->cood[0] = di*(kk+0.5);
							contact_p->cood[1] = dj*(kk+0.5);
							contact_p->distance = sqrt(pow(contact_p->cood[0], 2.0) + pow(contact_p->cood[1] , 2.0));
							contact_p->border = 1;
							contact_num++;
							contact_p++;
						}

						for(kk=1; kk<abs(ii)+1; kk++){
							tmp_dj = modf(dj*kk, &tmp_d);
							if(fabs(fabs(tmp_dj)-0.5)<EPS ) continue;

							contact_p->cood[0] = di*kk;
							contact_p->cood[1] = dj*kk;
							contact_p->distance = sqrt(pow(contact_p->cood[0], 2.0) + pow(contact_p->cood[1] , 2.0));
							contact_p->border = 0;
							contact_num++;
							contact_p++;
						}
					}

					/* contact with vertical */
					if(jj!=0){
						di=(double)ii/(double)abs(jj);
						dj=(double)jj/(double)abs(jj);
						contact_p->cood[0] = di*0.5;
						contact_p->cood[1] = dj*0.5;
						contact_p->distance = sqrt(pow(contact_p->cood[0], 2.0) + pow(contact_p->cood[1] , 2.0));
						contact_p->border = 2;
						contact_num++;
						contact_p++;
						for(kk=1; kk<abs(jj); kk++){
							contact_p->cood[0] = di*(kk+0.5);
							contact_p->cood[1] = dj*(kk+0.5);
							contact_p->distance = sqrt(pow(contact_p->cood[0], 2.0) + pow(contact_p->cood[1] , 2.0));
							contact_p->border = 2;
							contact_num++;
							contact_p++;
						}

						for(kk=1; kk<abs(jj)+1; kk++){
							tmp_di = modf(di*kk, &tmp_d);
							if(fabs(fabs(tmp_di)-0.5)<EPS ) continue;

							
							contact_p->cood[0] = di*kk;
							contact_p->cood[1] = dj*kk;
							contact_p->distance = sqrt(pow(contact_p->cood[0], 2.0) + pow(contact_p->cood[1] , 2.0));
							contact_p->border = 0;
							contact_num++;
							contact_p++;
						}
					}
					contact_num = contact_p - contact;

					/* remove same contact */
					qsort(contact, contact_num, sizeof(ST_CONTACT), ST_CONTACT_sort);
					for(contact_p = contact; contact_p < contact + contact_num; contact_p++){
						if(fabs(contact_p->distance - (contact_p+1)->distance) < EPS){
							/* contact with corner */
							if(contact_p->border!=0) contact_p->border = 3;
							(contact_p+1)->distance = 1000000.0;
							(contact_p+1)->cood[0]  = 1000000.0;
							(contact_p+1)->cood[1]  = 1000000.0;
							kk++;
						}
					}
					qsort(contact, contact_num, sizeof(ST_CONTACT), ST_CONTACT_sort);
					for(contact_p = contact; contact_p < contact + contact_num; contact_p++){
						if(fabs(contact_p->distance - 1000000.0) < EPS) break;
					}
					contact_num = contact_p - contact;

					/* move */
					fi=(ii==0)?0:abs(ii)/abs(ii);
					fj=(jj==0)?0:abs(jj)/abs(jj);
					Rii = RXi;
					Rjj = RXj;
					Sii = D;
					Sjj = D;
					sum_f = 0;
					for(contact_p = contact; contact_p < contact + contact_num; contact_p++){
						if(contact_p->border==0){
							if(ROOM[Rii][Rjj] == 2){
								tmp_di = modf(fabs(contact_p->cood[0]), &tmp_d);
								tmp_dj = modf(fabs(contact_p->cood[1]), &tmp_d);
								if(!((-EPS < tmp_di && tmp_di < EPS)||(-EPS < fabs(1.0-fabs(tmp_di)) && fabs(1.0-fabs(tmp_di)) < EPS))) continue;
								if(!((-EPS < tmp_dj && tmp_dj < EPS)||(-EPS < fabs(1.0-fabs(tmp_dj)) && fabs(1.0-fabs(tmp_dj)) < EPS))) continue;

								if(NGSIGHT[Sii][Sjj]==1) break;
								NGSIGHT[Sii][Sjj]=1;
								sum_f=1;
							}
						}else if(contact_p->border==1){/* contact with horizontal */
							Sii += ii/abs(ii);
							tmp_i = (int)(((double)fi * contact_p->cood[0])/fabs((double)fi * contact_p->cood[0]));
							if( ROOM[Rii+tmp_i][Rjj] == 0){
								fi *= -1;
							}else{
								Rii += tmp_i;
							}
						}else if(contact_p->border==2){/* contact with vertical */
							Sjj += jj/abs(jj);
							tmp_j = (int)(((double)fj * contact_p->cood[1])/fabs((double)fj * contact_p->cood[1]));
							if( ROOM[Rii][Rjj+tmp_j] == 0){
								fj *= -1;
							}else{
								Rjj += tmp_j;
							}
						}else if(contact_p->border==3){/* contact with corner */
							Sii += ii/abs(ii);
							Sjj += jj/abs(jj);
							tmp_i = (int)(((double)fi * contact_p->cood[0])/fabs((double)fi * contact_p->cood[0]));
							tmp_j = (int)(((double)fj * contact_p->cood[1])/fabs((double)fj * contact_p->cood[1]));

							horizontal = ROOM[Rii+tmp_i][Rjj];
							vertical = ROOM[Rii][Rjj+tmp_j];
							corner = ROOM[Rii+tmp_i][Rjj+tmp_j];
							if(corner!=0){
								Rii += tmp_i;
								Rjj += tmp_j;
							}else if(horizontal==0 && vertical==0){
								fi  *= -1;
								fj  *= -1;
							}else if(horizontal!=0 && vertical==0){
								Rii += tmp_i;
								fj  *= -1;
							}else if(horizontal==0 && vertical!=0){
								fi  *= -1;
								Rjj += tmp_j;
							}else if(horizontal!=0 && vertical!=0){
								break;
							}
						}
					}
					sum+=sum_f;
				}
			}
		}

		fprintf(fp_o, "Case #%d: %d\n", No, sum);
	}

	fclose(fp_i);
	fclose(fp_o);
}
	

