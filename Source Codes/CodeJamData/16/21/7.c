#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;
int l[256];
int d[10];
void solve(){
	char c;
	int i;
	int j;
	for(i=0; i<30; i++) l[i] = 0;
	for(i=0; i<10; i++) d[i] = 0;
	fscanf(fin, "%c", &c);
	do{
		l[c]++;
		fscanf(fin, "%c", &c);
	}while(c != '\n');

	while(l['Z']>0){
		d[0]++;
		l['Z']--;
		l['E']--;
		l['R']--;
		l['O']--;
	}

	while(l['W']>0){
		d[2]++;
		l['T']--;
		l['W']--;
		l['O']--;
	}

	while(l['U']>0){
		d[4]++;
		l['F']--;
		l['O']--;
		l['U']--;
		l['R']--;
	}

	while(l['X']>0){
		d[6]++;
		l['S']--;
		l['I']--;
		l['X']--;
	}

	while(l['G']>0){
		d[8]++;
		l['E']--;
		l['I']--;
		l['G']--;
		l['H']--;
		l['T']--;
	}

	while(l['G']>0){
		d[8]++;
		l['E']--;
		l['I']--;
		l['G']--;
		l['H']--;
		l['T']--;
	}
	while(l['O']>0){
		d[1]++;
		l['O']--;
		l['N']--;
		l['E']--;
	}

	while(l['R']>0){
		d[3]++;
		l['T']--;
		l['H']--;
		l['R']--;
		l['E']--;
		l['E']--;
	}

	while(l['F']>0){
		d[5]++;
		l['F']--;
		l['I']--;
		l['V']--;
		l['E']--;
	}

	while(l['V']>0){
		d[7]++;
		l['S']--;
		l['E']--;
		l['V']--;
		l['E']--;
		l['N']--;
	}
	while(l['I']>0){
		d[9]++;
		l['N']--;
		l['I']--;
		l['N']--;
		l['E']--;
	}
	for(i=0; i<10; i++){
		for(j=0; j<d[i]; j++){
			fprintf(fout, "%d", i);
		}
	}
	fprintf(fout,"\n");


}

int main(int argc, char *argv[]){
	char kk;
	int total, i;

	fin=fopen(argv[1], "r");
	fout=fopen("out", "w");
	if (fin==NULL || fout == NULL)
	{
		printf("Fitxer out.\n");
	}
	else 
	{
		fscanf(fin, "%d", &total);
		fscanf(fin, "%c", &kk);
		for (i = 0; i<total; i++)
		{
			fprintf(fout, "Case #%d: ", i+1);
			solve();
		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}