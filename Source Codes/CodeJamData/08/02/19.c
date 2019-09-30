#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

struct train{
	int status;
	int dest;
	int time;
};

train tr[202];
int turnaround;

int AT[101][2],BT[101][2];
int NA,NB;
int ra,rb;
int ta,tb;

int main()
{
	int cc,ca;
	int i,j,k;
	scanf("%d", &ca);
	for(cc=1;cc<=ca;cc++)
	{
		scanf("%d", &turnaround);
		scanf("%d %d", &NA, &NB);
		char buf[1024];
		fgets(buf, 1024, stdin);
		for(i=0; i<NA; i++)
		{
			fgets(buf, 1024, stdin);
			for(j=0; j<strlen(buf); j++)
				if (buf[j] == ':')
					buf[j] = ' ';
			int a,b,c,d;
			sscanf(buf, "%d %d %d %d", &a, &b, &c, &d);
			AT[i][0] = a*60+b;
			AT[i][1] = c*60+d;
		}
		for(i=0; i<NB; i++)
		{
			fgets(buf, 1024, stdin);
			for(j=0; j<strlen(buf); j++)
				if (buf[j] == ':')
					buf[j] = ' ';
			int a,b,c,d;
			sscanf(buf, "%d %d %d %d", &a, &b, &c, &d);
			BT[i][0] = a*60+b;
			BT[i][1] = c*60+d;
		}
/*		for(i=0; i<NA; i++)
			cout << AT[i][0] << ' ' << AT[i][1] << endl;
		for(i=0; i<NB; i++)
			cout << BT[i][0] << ' ' << BT[i][1] << endl;
*/
		memset(tr, 0, sizeof(tr));
		ra = 0; rb = 0;
		ta = 0; tb = 0;
		for(int time = 0; time<=24*60; time++)
		{
			// update train
			for(i=0; i<200; i++)
			{
				if (tr[i].status == 2)
				{
					tr[i].time--;
					if (tr[i].time == 0)
					{
						tr[i].time = turnaround;
						tr[i].status = 1;
						if (turnaround == 0)
						{
							tr[i].status = 0;
							if (tr[i].dest == 0)
								ta++;
							else
								tb++;
						}
					}
				}
				else if (tr[i].status == 1)
				{
					tr[i].time--;
					if (tr[i].time == 0)
					{
						tr[i].status = 0;
						if (tr[i].dest == 0)
							ta++;
						else
							tb++;
					}
				}
			}

			for(i=0; i<NA; i++)
			{
				if (AT[i][0] == time)
				{
					for(j=0; j<200; j++)
						if (tr[j].status == 0)
							break;
					tr[j].status = 2;
					tr[j].time = AT[i][1] - AT[i][0];
					tr[j].dest = 1;
					ta--;
					if (ta < ra) ra = ta;
				}
			}
			for(i=0; i<NB; i++)
			{
				if (BT[i][0] == time)
				{
					for(j=0; j<200; j++)
						if (tr[j].status == 0)
							break;
					tr[j].status = 2;
					tr[j].time = BT[i][1] - BT[i][0];
					tr[j].dest = 0;
					tb--;
					if (tb < rb) rb = tb;
				}
			}
		}
		printf("Case #%d: %d %d\n", cc, -ra, -rb);
	}
}
