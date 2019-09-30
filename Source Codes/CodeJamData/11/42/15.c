#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int plate[601][601];
long long sum_r[601][601], sum_c[601][601];
int R, C, D;

int getlinesum_r(int i, int j, int i2)
{
	if (i > 0)
		return sum_r[i2][j] - sum_r[i-1][j];
	else
		return sum_r[i2][j];	
}

int getlinesum_c(int i, int j, int j2)
{
	if (j > 0)
		return sum_c[i][j2] - sum_c[i][j-1];
	else
		return sum_c[i][j2];
}

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> R >> C >> D;
		for(i=0; i<R; i++)
		{
			string s;
			cin >> s;
			for(j=0; j<C; j++)
				plate[i][j] = s[j]-'0';
		}
		for(i=0; i<R; i++) for(j=0; j<C; j++)
		{
			if (i > 0)
				sum_r[i][j] = sum_r[i-1][j] + plate[i][j];
			else
				sum_r[i][j] = plate[i][j];

			if (j > 0)
				sum_c[i][j] = sum_c[i][j-1] + plate[i][j];
			else
				sum_c[i][j] = plate[i][j];
		}

		int w = min(R, C);
		int found = -1;
		while(w >= 3)
		{
			for(i=0; i<R-w+1; i++) for(j=0; j<C-w+1; j++)
			{
				long long l,r,u,d;
				l = r = 0;
				int weight = w/2;
				for(k=0; k<w/2; k++)
				{
					l += getlinesum_r(i, j+k, i+w-1)*weight;
					r += getlinesum_r(i, j+w-1-k, i+w-1)*weight;
					weight--;
				}
				l -= (plate[i][j] + plate[i+w-1][j])*(w/2);
				r -= (plate[i][j+w-1] + plate[i+w-1][j+w-1])*(w/2);
//				printf("[%d %d] %d l:%lld r:%lld\n", i, j, w, l, r);
				if (l != r) continue;
				u = d = 0;
				weight = w/2;
				for(k=0; k<w/2; k++)
				{
					u += getlinesum_c(i+k, j, j+w-1)*weight;
					d += getlinesum_c(i+w-1-k, j, j+w-1)*weight;
					weight--;
				}
				u -= (plate[i][j] + plate[i][j+w-1])*(w/2);
				d -= (plate[i+w-1][j] + plate[i+w-1][j+w-1])*(w/2);
//				printf("[%d %d] %d u:%lld d:%lld\n", i, j, w, u, d);
				if (u != d) continue;
				found = w;
				goto done;
			}
			w--;
		}
done:
		if (found < 0)
			printf("Case #%d: IMPOSSIBLE\n", cc);
		else
			printf("Case #%d: %d\n", cc, found);
	}
}
