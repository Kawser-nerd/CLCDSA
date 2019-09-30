#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int nbChest=0;
int *chestOpenKey;
int **chestObtainKeys;

void disp(int *avalKeys,int *chestStatus)
{
	printf("Status :");
	for(int i=0;i<nbChest;++i)
	{
		printf(" %d",chestStatus[i]);
	}
	printf("\n");
	printf("Keys :");
	for(int i=0;i<20;++i)
	{
		printf(" %d",avalKeys[i]);
	}
	printf("\n");
	return;
}

int test(int iStep,int *avalKeys,int *chestStatus)
{
	//disp();
	int step=iStep;
	if(step>nbChest) return 1;
	if(step==1)
	{
		int doLoop=1;
		while(doLoop==1)
		{
			doLoop=0;
			for(int i=0;i<nbChest;++i)
			{
				if(chestStatus[i]==0)
				{
					int key=chestOpenKey[i];
					if(avalKeys[key]>0)
					{
						int ok=0;
						int nb=chestObtainKeys[i][0];
						for(int j=1;j<=nb;++j)
						{
							int oKey=chestObtainKeys[i][j];
							if(oKey==key) ok=1;
						}
						if(ok==1)
						{
							avalKeys[key]-=1;
							for(int k=1;k<=nb;++k)
							{
								int oKey=chestObtainKeys[i][k];
								avalKeys[oKey]+=1;
							}
							chestStatus[i]=step;
							step++;
							doLoop=1;
						}
					}
				}
			}
		}	
	}
	int skip=0;
	for(int i=0;i<nbChest;++i)
	{
		//disp();
		//printf("Chest # %d - \n",i);
		if(chestStatus[i]==0)
		{
			int key=chestOpenKey[i];
			//printf("open key : %d\n",key);
			if(avalKeys[key]>0)
			{
				int nb=chestObtainKeys[i][0];
				if(nb==0)
				{
					skip=1;
					continue;
				}
				avalKeys[key]-=1;
				for(int j=1;j<=nb;++j)
				{
					int oKey=chestObtainKeys[i][j];
					avalKeys[oKey]+=1;
				}
				chestStatus[i]=step;
				if(test(step+1,avalKeys,chestStatus)==1) return 1;
				chestStatus[i]=0;
				for(int j=1;j<=nb;++j)
				{
					int oKey=chestObtainKeys[i][j];
					avalKeys[oKey]-=1;
				}
				avalKeys[key]+=1;
			}
		}
	}
	int restStep=nbChest;
	if(skip==1)
	{
		for(int i=0;i<nbChest;++i)
		{
			//printf("Chest # %d - ",i);
			if(chestStatus[i]==0)
			{
				int nb=chestObtainKeys[i][0];
				if(nb==0)
				{
					int key=chestOpenKey[i];
					//printf("open key : %d\n",key);
					if(avalKeys[key]>0)
					{
						avalKeys[key]-=1;
						chestStatus[i]=restStep;
						restStep--;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
		}
		return 1;
	}
	for(int i=0;i<nbChest;++i)
	{
		if(chestStatus[i]==0)
		{
			return 0;
		}
	}
	return 1;
}

void test2(int *avalKeys,int *chestStatus)
{
	for(int s=1;s<=nbChest;++s)
	{
		for(int i=0;i<nbChest;++i)
		{
			int *tmpChestStatus=(int *)calloc(nbChest,sizeof(int));
			memcpy(tmpChestStatus,chestStatus,nbChest*sizeof(int));
			int *tmpAvalKeys=(int *)calloc(201,sizeof(int));
			memcpy(tmpAvalKeys,avalKeys,201*sizeof(int));
			if(tmpChestStatus[i]==0)
			{
				int key=chestOpenKey[i];
				if(tmpAvalKeys[key]>0)
				{
					tmpAvalKeys[key]-=1;
					int nb=chestObtainKeys[i][0];
					for(int j=1;j<=nb;++j)
					{
						int oKey=chestObtainKeys[i][j];
						tmpAvalKeys[oKey]+=1;
					}
					tmpChestStatus[i]=s;
					if(test(s+1,tmpAvalKeys,tmpChestStatus)==1)
					{
						avalKeys[key]-=1;
						for(int k=1;k<=nb;++k)
						{
							int oKey=chestObtainKeys[i][k];
							avalKeys[oKey]+=1;
						}
						chestStatus[i]=s;
						break;
					}
				}
			}
		}
	}
}

int main()
{
	FILE *pInput,*pOutput;
	pInput=fopen("input.txt","r");
	pOutput=fopen("output.txt","w+");
	int nbCase=0;
	fscanf(pInput,"%d\n",&nbCase);
	printf("nbCase : %d\n",nbCase);
	for(int i=0;i<nbCase;++i)
	{
		nbChest=0;
		chestOpenKey=NULL;
		chestObtainKeys=NULL;
		printf("case %d - start (nbCase : %d)\n",i+1,nbCase);
		int nbKeys;
		fscanf(pInput,"%d %d\n",&nbKeys,&nbChest);
		//printf("%d keys, %d chests\n",nbKeys,nbChest);
		int *avalKeys=(int *)calloc(201,sizeof(int));
		int *avalKeys2=(int *)calloc(201,sizeof(int));
		//printf("given keys : ");
		for(int j=0;j<nbKeys;++j)
		{
			int key=0;
			fscanf(pInput,"%d",&key);
			avalKeys[key]+=1;
			avalKeys2[key]+=1;
			//printf("%d ",key);
		}
		fscanf(pInput,"\n");
		//printf("\n");
		int *chestStatus=(int *)calloc(nbChest,sizeof(int));
		int *chestStatus2=(int *)calloc(nbChest,sizeof(int));
		chestOpenKey=(int *)calloc(nbChest,sizeof(int));
		chestObtainKeys=(int **)calloc(nbChest,sizeof(int *));
		for(int j=0;j<nbChest;++j)
		{
			int key=0,nb=0;
			fscanf(pInput,"%d",&key);
			chestOpenKey[j]=key;
			//printf("  open key : %d\n",key);
			fscanf(pInput,"%d",&nb);
			//printf("    obtain %d keys : ",nb);
			chestObtainKeys[j]=(int *)calloc(nb+1,sizeof(int));
			chestObtainKeys[j][0]=nb;
			for(int k=1;k<=nb;++k)
			{
				fscanf(pInput,"%d",&key);
				chestObtainKeys[j][k]=key;
				//printf("%d ",key);
			}
			//printf("\n");
		}
		fscanf(pInput,"\n");
		if(test(1,avalKeys,chestStatus)==0)
		{
			fprintf(pOutput,"Case #%d: IMPOSSIBLE\n",(i+1));
			printf("Case #%d: IMPOSSIBLE\n",(i+1));
		}
		else
		{
			test2(avalKeys2,chestStatus2);
			fprintf(pOutput,"Case #%d:",(i+1));
			printf("Case #%d:",(i+1));
			for(int j=1;j<=nbChest;++j)
			{
				for(int k=0;k<nbChest;++k)
				{
					if(chestStatus2[k]==j)
					{
						fprintf(pOutput," %d",k+1);
						printf(" %d",k+1);
						break;
					}
				}
			}
			fprintf(pOutput,"\n");
			printf("\n");
		}
	}
	return 0;
}