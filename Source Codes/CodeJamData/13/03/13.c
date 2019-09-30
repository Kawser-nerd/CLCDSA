#include <stdio.h>
// std=c99


int isPalindrome(int n) // this is with assumption only 3 digit max
{
	if (n < 10)
		return 1;
	
	if (n < 100)
	{
		int first = n / 10;
		int second = n % 10;
		return first == second;	
	}
	else
	{
		int first = n / 100;
		int last = n % 10;
		return first == last;			
	}
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	int isFairAndSquare[1001];
	int isFair[31];
	
	for (int i=0; i<=1000; i++)
	{
		isFairAndSquare[i] = 0;
	}
	
	for (int i=0; i<=31; i++)
	{
		if (isPalindrome(i))
		{
			int fas = i * i;
			if (isPalindrome(fas))
			{
				isFairAndSquare[fas] = 1;				
			}
		}		
	}
	
	for (int i=1; i<=n; i++)
	{
		int counter = 0;
		
		int start;
		int end;

		scanf("%d %d", &start, &end);
		
		for (int j=start; j<=end; j++)
		{
			if (isFairAndSquare[j])
			{
				counter++;
			}
		}
		
		printf("Case #%d: %d\n", i, counter);
	}
}
