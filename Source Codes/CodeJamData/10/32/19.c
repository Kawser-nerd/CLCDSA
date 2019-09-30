#include<stdio.h>
#include<string.h>

int main()
{
    char filename[32];
	char infile[32], outfile[32];
	FILE *fp, *ofp;	
	int tc, t, c, cnt, check;
	long  low, up;
	long long num;
		
	scanf("%s", filename);
	
	strcpy(infile, filename); 
	strcpy(outfile, filename);
	strcat(infile, ".in"); 
	strcat(outfile, ".out");
	
	fp=fopen(infile, "r"), 
	ofp=fopen(outfile, "w");

	fscanf(fp, "%d\n", &tc);
	//scanf("%d",&tc);
	for(t=1;t<=tc;t++)//line no
	{
		fscanf(fp, "%ld %ld %d\n", &low, &up, &c);
		//scanf("%ld %ld %d\n", &low, &up, &c);
		cnt=0;
		num=low;
		if(num==0)
			num=1;
		check=0;
		while(num*c<up)						
		{
			num*=c;
			cnt++;
		}
		if(cnt==0)
			fprintf(ofp, "Case #%d: 0\n",t);
			//printf("Case #%d: 0\n",t);
		else
		{
			while(cnt>=1)
			{
				cnt=cnt>>1;
				check++;
			}	
			fprintf(ofp, "Case #%d: %ld\n",t,check);
			//printf("Case #%d: %ld\n",t,check);
		}		
	}
	return 0;
}


	
