#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <glib.h>
#define PI 3.14159265358979323846
int N,K;
int R[1000],H[1000];
long double Ac[1000],Av[1000],At[1000],finalAns = -1;
/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int indexarr[], int start, int end,
                     int index, int r)
{
	int i,j;
	long double Ans = 0;
    // Current combination is ready to be printed, print it
    if (index == r)
    {
    	Ans = 0;
        for (j=0; j<r; j++)
        {
        	if(j>0)
        	{
        		Ans -= Ac[indexarr[j]];
        	}
        	Ans += At[indexarr[j]];
        }
        if(Ans > finalAns)
        {
        	finalAns = Ans;
        }
        //    printf("%d ", data[j]);
        //printf("\n");
        return;
    }
 
    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        indexarr[index] = i;
        combinationUtil(arr, data, indexarr, i+1, end, index+1, r);
    }
}
// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
    // A temporary array to store all combination one by one
    int data[r];
    int index[r];
 
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, index, 0, n-1, 0, r);
}
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j, temp;
   long double tempd;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] < arr[j+1]||(arr[j]==arr[j+1]&&At[j]<At[j+1])){
           	temp = arr[j];
           	arr[j] = arr[j+1];
           	arr[j+1] = temp;
           	
           	temp = H[j];
           	H[j] = H[j+1];
           	H[j+1] = temp;
           	
           	tempd = Ac[j];
           	Ac[j] = Ac[j+1];
           	Ac[j+1] = tempd;
           	
           	tempd = Av[j];
           	Av[j] = Av[j+1];
           	Av[j+1] = tempd;
           	
           	tempd = At[j];
           	At[j] = At[j+1];
           	At[j+1] = tempd;
           }
}
void main()
{
	int n = 0;
	int cases;
	int i,j,k;
	scanf("%d",&cases);
	while(n<cases)
	{
		finalAns = -1;
		n++;
		printf("Case #%d: ",n);
		
		//Logic to print answer for this case goes here
		scanf("%d%d",&N,&K);
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&R[i],&H[i]);
			Ac[i] = PI*R[i]*R[i];
			Av[i] = 2*PI*R[i]*H[i]; 
			At[i] = Ac[i]+Av[i];
		}
		bubbleSort(R,N);
		/*for(i=0;i<N;i++)
		{
			printf("%d %d %Lf %Lf %Lf\n",R[i],H[i],Ac[i],Av[i],At[i]);
		}*/
		
		printCombination(R, N, K);
		
		printf("%Lf",finalAns);
		printf("\n");
	}
}
