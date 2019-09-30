#include <stdio.h>

struct group{
	unsigned long people;
	unsigned long to;
	unsigned long euros;
}GROUP[1000];

int fill_group(int n_group, int size){
	int i;
	int packet;
	int j;
	for(i=0;i<n_group;i++){
		j=i;
		packet=GROUP[i].people;
		GROUP[i].euros=0;
		while(packet<=size){
			GROUP[i].euros+=GROUP[j].people;

			j++;
			j%=n_group;
			packet+=GROUP[j].people;

			if(j==i)
				break;
		}
		GROUP[i].to=j;
		if (GROUP[i].euros==0){
			fprintf(stderr,"euros=0!!!\n");
			return -1;
		}
		//fprintf(stderr,"%ld %ld %ld\n",GROUP[i].people,GROUP[i].euros,GROUP[i].to);
	}

	return 0;
}

unsigned long calculate_euros(int rounds){
	unsigned long euros=0;
	int where=0;
	unsigned long i;

	for (i=0;i<rounds;i++){
		euros+=GROUP[where].euros;
		where=GROUP[where].to;
	}
	return euros;
}

int main(int argc, char *argv[]){
	unsigned long cases;
	unsigned long groups;
	unsigned long size;
	unsigned long rounds;
	unsigned long euros;
	unsigned long i,j;

	if (1!=scanf("%ld",&cases)){
		fprintf(stderr,"%d\n",__LINE__);
		return -1;
	}

	for (i=1;i<=cases;i++){
		if (3!=scanf("%ld %ld %ld",&rounds,&size,&groups)){
			fprintf(stderr,"%d\n",__LINE__);
			return -1;
		}
		for (j=0;j<groups;j++){
			if (1!=scanf("%ld",&GROUP[j].people)){
				fprintf(stderr,"%d\n",__LINE__);
				return -1;
			}
		}
		fill_group(groups,size);
		euros=calculate_euros(rounds);
		fprintf(stdout,"Case #%ld: %ld\n",i,euros);
	}

	return 0;
}
