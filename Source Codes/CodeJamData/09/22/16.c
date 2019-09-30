#include <stdio.h>
#include <string.h>


int strCount;
char eachCount[30];

void add_string(char strNumber[], int star_point)
{
	int i,j;

	for(i = star_point; i < strCount; i++)
	{
		
		for(j = 0; j < 10; j++)
			if(eachCount[j] > 0)
			{
				strNumber[i] = j + '0';
				eachCount[j]--;
				break;
			}
	}
}

int main()
{
	int no_case;
	int i, j, k;
	char strNumber[100];
	
	

	scanf("%d", &no_case);

	for(k = 0; k < no_case; k++)
	{
		memset(eachCount, 0, sizeof(eachCount));
		scanf("%s", strNumber);

		strCount = strlen(strNumber);

		eachCount[strNumber[strCount-1]-'0']++;
 
		for(i = strCount - 2; i >= 0; i--)
		{
			eachCount[strNumber[i]-'0']++;
			if(strNumber[i] < strNumber[i+1])
			{

				
				for(j = strNumber[i]-'0'+1; j < 10; j++)
					if(eachCount[j] > 0)
					{
						strNumber[i] = j + '0';
						eachCount[j]--;
						add_string(strNumber, i+1);
						break;
					}

				break;
			}
		} 
		
		if(i < 0)
		{
			for(j = 1; j < 10; j++)
				if(eachCount[j] > 0)
				{
					strNumber[0] = j + '0';
					strNumber[1] = '0';
					eachCount[j]--;
					break;
				}
			strCount++;
			add_string(strNumber, 2);

			strNumber[strCount] = 0;
		}
		
		printf("Case #%d: %s\n", k+1, strNumber);

	}

	



	return 0;
}
    