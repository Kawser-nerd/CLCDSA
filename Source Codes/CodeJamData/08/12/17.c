#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int** zeros;
int** ones;

int check_compatibility(int* bitmap,int num_flavors,int num_customers)
{

	int i;
	int j;
	int found = 0;

	for(i = 0; i< num_customers; i++)
	{

		int num_matches = 0;
		for(j=0; j < num_flavors; j++)
		{

		if(zeros[i][j] && (bitmap[j] == 0) ) { num_matches++; break; }
		if(ones[i][j] && (bitmap[j] == 1) ) { num_matches++; break; }
		}

		if(num_matches == 0) { return 0;}
	}

	return 1;

}

void increment(int* bitmap, int num_flavors)
{
	int i;
	int j;

	for(i =0; i< num_flavors; i++)
	{
		if(bitmap[i] == 0 ) { bitmap[i] = 1; return;}
		else {
			if(i == num_flavors-1) { return;}

			 bitmap[i] = 0;
			for(j = i+1; j < num_flavors; j ++)
			{
				if(bitmap[j] == 0 ) { bitmap[j] = 1; return;}
				else { bitmap[j] = 0; }
			}
		}
	}
}

int check_num_ones(int* bitmap, int num_flavors)
{
	int sum = 0;
	int i;

	for(i =0; i< num_flavors; i++)
	{
		sum += bitmap[i];
	}

	return sum;
}


int main(int c, char** argv)
{

	int num_cases;
	int i;

	FILE* inf;

	inf = fopen(argv[1],"r");

	fscanf(inf,"%d",&num_cases);

	for(i=0;i<num_cases;i++)
	{
		int* bitmap;
		int num_flavors;
		int num_customers;
		int j,k;
		int min_found_till_now = 10000;
		int* answer_bitmap;

		fscanf(inf,"%d",&num_flavors);

		fscanf(inf,"%d",&num_customers);


		bitmap = (int*) calloc(num_flavors,sizeof(int));

		answer_bitmap = (int*) calloc(num_flavors,sizeof(int));

		zeros = (int**) calloc(num_customers,sizeof(int*));
		ones = (int**) calloc(num_customers,sizeof(int*));


		for(j= 0; j< num_customers;j++)
		{
			zeros[j] = (int*) calloc(num_flavors,sizeof(int));
			ones[j] = (int*) calloc(num_flavors,sizeof(int));
		}
	
		for(j= 0; j< num_customers;j++)
		{
			int likes;

			fscanf(inf,"%d",&likes);

			for(k= 0; k< likes;k++)
			{
				int flavorid;
				int malted;

				fscanf(inf,"%d %d",&flavorid,&malted);
				
				if(malted) { ones[j][flavorid-1] = 1; } 
				else { zeros[j][flavorid-1] = 1; } 
			}
		}
	

		for(j=0; j < (int)(pow(2.0,num_flavors)); j++ )
		{
			if(check_compatibility(bitmap,num_flavors,num_customers))
			{
				int k = check_num_ones(bitmap,num_flavors);
				if(k < min_found_till_now)
				{
					min_found_till_now = k;
					memcpy(answer_bitmap,bitmap,sizeof(int)*num_flavors);
				}

			}

			increment(bitmap,num_flavors);
		}


		if(min_found_till_now == 10000) { printf("Case #%d: IMPOSSIBLE\n",i+1);}
		else {
			printf("Case #%d: ",i+1);
			
			for(j=0;j<num_flavors;j++)
			{
				printf("%d ",answer_bitmap[j]);
			}
			
			printf("\n");
			
		}




		for(j= 0; j< num_customers;j++)
		{
			free(zeros[j]); // = (int*) calloc(num_flavors,sizeof(int));
			free(ones[j]); // = (int*) calloc(num_flavors,sizeof(int));
		}

		
		
		free(ones);
		free(zeros);
		free(bitmap);

	
	}

}
