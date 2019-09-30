#include <stdio.h>
#include <string.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    int curcase = 0;
    while (t != curcase)
    {
        int n, m;
	scanf("%d %d", &n, &m);
	char As[n * n];
	char Bs[n * n];
	memset(As, 0, n * n);
	memset(Bs, 0, n * n);
	for (int i = 0; i < m; i++)
	{
	    char s[2];
	    int row, col;
	    scanf("%s %d %d", s, &row, &col);
	    row--;
	    col--;
	    if (s[0] == 'o')
	    {
	        As[row * n + col] = 1;
		Bs[row * n + col] = 1;
	    }
	    else if (s[0] == 'x')
	    {
	        Bs[row * n + col] = 1;
	    }
	    else
	    {
	        As[row * n + col] = 1;
	    }
	}
	char Ascpy[n * n];
	char Bscpy[n * n];
	memcpy(Ascpy, As, n * n);
	memcpy(Bscpy, Bs, n * n);
	char usedrows[n];
	char usedcols[n];
	memset(usedrows, 0, n);
	memset(usedcols, 0, n);
	for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < n; j++)
	    {
	        if (Bs[i * n + j])
		{
		    usedrows[i] = 1;
		    usedcols[j] = 1;
		    break;
		}
	    }
	}
	for (int i = 0; i < n; i++)
	{
	    if (usedrows[i])
	    {
	        continue;
	    }
	    for (int j = 0; j < n; j++)
	    {
	        if (!usedcols[j])
		{
		    Bs[i * n + j] = 1;
		    usedcols[j] = 1;
		    usedrows[i] = 1;
		    break;
		}
	    }
	}
	int atng[n * n]; /*attacking*/
	int lowest;
	while (1)
	{
	lowest = 1000;
	for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < n; j++)
	    {
	        if (As[i * n + j])
		{
		    atng[i * n + j] = -1;
		    continue;
		}
		int attacking = 0;
		for (int k = -1 * n; k < n; k++)
		{
		    int row = i + k;
		    int col = j + k;
		    if (k == 0 || row < 0 || row >= n || col < 0 || col >= n)
		    {
		        continue;
		    }
		    if (As[row * n + col])
		    {
		        attacking = -1;
			break;
		    }
		    attacking++;
		}
		if (attacking == -1)
		{
		    atng[i * n + j] = -1;
		    continue;
		}
		for (int k = -1 * n; k < n; k++)
		{
		    int row = i - k;
		    int col = j + k;
		    if (k == 0 || row < 0 || row >= n || col < 0 || col >= n)
		    {
		        continue;
		    }
		    if (As[row * n + col])
		    {
		        attacking = -1;
			break;
		    }
		    attacking++;
		}
		atng[i * n + j] = attacking;
		if (attacking != -1 && attacking < lowest)
		{
		    lowest = attacking;
		}
	    }
	}
	if (lowest == 1000)
	{
	    break;
	}
	for (int i = 0; i < n; i++)
	{
	    char found = 0;
	    for (int j = 0; j < n; j++)
	    {
	        
	        if (atng[i * n + j] == lowest)
		{
		    As[i * n + j] = 1;
		    found = 1;
		    break;
		}
	    }
	    if (found)
	    {
	        break;
	    }
	}
	}
	int changes = 0;
	int score = 0;
	for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < n; j++)
	    {
	        int loc = i * n + j;
	        if (As[loc])
		{
		    score++;
		}
		if (Bs[loc])
		{
		    score++;
		}
		if (As[loc] != Ascpy[loc] || Bs[loc] != Bscpy[loc])
		{
		    changes++;
		}
	    }
	}
	printf("Case #%d: %d %d\n", curcase + 1, score, changes);
	for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < n; j++)
	    {
	        int loc = i * n + j;
	        if (As[loc] != Ascpy[loc] || Bs[loc] != Bscpy[loc])
		{
		    char c;
		    if (!As[loc])
		    {
		        c = 'x';
		    }
		    else if (!Bs[loc])
		    {
		        c = '+';
		    }
		    else
		    {
		        c = 'o';
		    }
		    printf("%c %d %d\n", c, i + 1, j + 1);
		}
	    }
	}
	curcase++;
    }
    return 0;
}
