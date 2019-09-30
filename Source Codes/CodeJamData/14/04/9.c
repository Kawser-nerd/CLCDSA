/*
    By Yemeli Tasse Cyrille
    http://yemelitc.org
    Date: 12 April 2014
*/


#include<stdio.h>

void quicksort (double* list, int m, int n);
void printArray (double* list, int size);


int main()
{
	int i, j, l;
	int cases, T;

    int N, fair, unfair;
    double Naomi[1000];
    double Ken[1000];

	FILE *output = fopen("D-large.out", "w");
	FILE *input = fopen("D-large.in", "r");
	fscanf(input, "%d", &T);

	for(cases=1; cases<=T; cases++)
	{
		fscanf(input, "%d", &N);
		
		for(i=0; i<N; i++)
		    fscanf(input, "%lf", &Naomi[i]);
		
		for(i=0; i<N; i++)
		    fscanf(input, "%lf", &Ken[i]);

		//printArray (Naomi, N);
		quicksort (Naomi, 0, N-1);
		//printArray (Naomi, N);

		//printArray (Ken, N);
		quicksort (Ken, 0, N-1);
		//printArray (Ken, N);
		
		fair=0;
		for(i=0, j=0; j<N; j++)
		{
		    if(Naomi[i] > Ken[j])
		        fair++;
		    else i++;
		}
		
		unfair=0;
		i=0;
		j=N-1;
		l=N-1;
		
		while(i<=l)
		{
		    if(Naomi[l] > Ken[j])
		        { unfair++; l--; j--; }
            else
                { i++; j--; }
		}
		
		fprintf(output, "Case #%d: %d %d\n", cases, unfair, fair);
		printf("Case #%d: %d %d\n", cases, unfair, fair);
	}

	fclose(input);
	fclose(output);
}





void swap(double *x, double *y)
{ double temp=*y; *y=*x; *x=temp; }

void quicksort (double *array, int start, int stop)
{
	// if base case
	if (start>=stop) return;

	int i=start+1, j, middle=start+(stop-start)/2;

	// make sure pivot is at first elemtent [0]
	if (array[middle]>=array[start] && array[middle]<=array[stop])
		swap(&array[start], &array[middle]);
	else if (array[middle]<=array[start] && array[middle]>=array[stop])
		swap(&array[start], &array[middle]);
	
	else if (array[stop]>=array[start] && array[stop]<=array[middle])
		swap(&array[start], &array[stop]);
	else if (array[stop]<=array[start] && array[stop]>=array[middle])
		swap(&array[start], &array[stop]);
	
	// start iteration over the array
	for(j=start+1; j<=stop; j++)
		if(array[j]<array[start])
			swap(&array[j], &array[i++]);

	// conclude by putting the pivot from first element
	// to the appropriate position of the sorted array
	if(start!=i-1) swap(&array[start], &array[i-1]);
	
	//recursively sort sub-arrays
	quicksort(array, start, i-2);
	quicksort(array, i, stop);
}


void printArray (double* list, int size)
{
    int i;
    for(i=0; i<size; i++)
        printf(" %.3lf", list[i]);
    printf("\n");
}

