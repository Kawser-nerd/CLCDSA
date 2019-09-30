
#include <stdio.h>
#include <string.h>

int turnaround;
int diff[2][1440];

static void parse(int nx, int from, int to)
{
    for (int i = 0; i < nx; i++)
    {
	int h1, m1, h2, m2;
	scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);

	int t1 = h1*60+m1;
	int t2 = h2*60+m2 + turnaround;

	diff[from][t1]--;
	if (t2 < 1440)
	    diff[to][t2]++;
    }
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
	int na, nb;
	scanf("%d %d %d", &turnaround, &na, &nb);

	memset(diff, 0, sizeof(diff));
	parse(na, 0, 1);
	parse(nb, 1, 0);

	int min[2] = {0, 0};
	for (int j = 0; j < 2; j++)
	{
	    int cur = 0;
	    for (int k = 0; k < 1440; k++)
	    {
		cur += diff[j][k];
		if (cur < min[j])
		    min[j] = cur;
	    }
	}

	printf("Case #%d: %d %d\n", i, -min[0], -min[1]);
    }
}

