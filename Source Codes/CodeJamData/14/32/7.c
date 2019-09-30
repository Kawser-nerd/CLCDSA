#include <stdio.h>


/* Basic integer array version */
/* 
 * Computes the next lexicographical permutation of the specified array of integers in place,
 * returning a Boolean to indicate whether a next permutation existed.
 * (Returns false when the argument is already the last possible permutation.)
 */
int next_permutation(int *array, int length) {
	int i, j;
	int temp;
	
	// Find non-increasing suffix
	i = length - 1;
	while (i > 0 && array[i - 1] >= array[i])
		i--;
	if (i <= 0)
		return 0;
	
	// Find successor to pivot
	j = length - 1;
	while (array[j] <= array[i - 1])
		j--;
	temp = array[i - 1];
	array[i - 1] = array[j];
	array[j] = temp;
	
	// Reverse suffix
	j = length - 1;
	while (i < j) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
	return 1;
}

char cars[500][500];
char train[1000];

int uniqlen(char* s)
{
    char prev = '?';
    int len = 0;
    for (char* c = s; *c; c++)
    {
        if (*c != prev)
            len++;
        prev = *c;
    }
    return len;
}

void join(int* ind, int n)
{
    train[0] = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        len += snprintf(train+len, sizeof(train)-len, cars[ind[i]]);
    }
}

int uniqchars(char* s)
{
    int count[255] = {0};
    for (char* c = s; *c; c++)
    {
        count[*c] = 1;
    }
    int len = 0;
    for (int i = 0; i < 255; i++)
    {
        len += count[i];
    }
    return len;
}

int valid(int* ind, int n)
{
    join(ind, n);
    //~ printf("%s\n", train);
    int lu = uniqlen(train);
    int lu2 = uniqchars(train);
    return lu == lu2;
}

int T;
void main()
{
    scanf("%d\n", &T);

    for (int t = 0; t < T; t++)
    {
        int ind[10] = {0,1,2,3,4,5,6,7,8,9};
        int n = 0;
        scanf("%d\n", &n);
        
        
        for (int i = 0; i < n; i++)
        {
            scanf("%[a-z] ", cars[i]);
            //~ printf("%s\n", cars[i]);
        }
        scanf("\n");

        
        int k = 0;
        int sol = 0;
        do
        {
            k++;
            //~ printf("%s %s %s\n", cars[ind[0]], cars[ind[1]], cars[ind[2]]);
            //~ printf("%d\n", valid(ind,n));
            sol += valid(ind, n);
        } while (next_permutation(ind, n));

        printf("Case #%d: %d\n", t+1, sol);
        //~ printf("%d %d\n", n, k);
    }
}
