#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int val, id, aux;
}tipo;

#define MAX 1024

int n, cnt;
tipo v1[MAX], v2[MAX];

char foi1[MAX], foi2[MAX];

int fc1 (const void *e1, const void *e2)
{
	tipo *p1, *p2;
	
	p1 = (tipo*)e1;
	p2 = (tipo*)e2;
	
	if (p1->val != p2->val)
		return p1->val - p2->val;
	return p2->aux - p1->aux;
}

int fc2 (const void *e1, const void *e2)
{
	tipo *p1, *p2;
	
	p1 = (tipo*)e1;
	p2 = (tipo*)e2;
	
	return p1->val - p2->val;
}


int pega1()
{
	int i;
	int aux, q = -1;
	for (i=0; i<n; i++)
	{
		if (foi1[v1[i].id])
			continue;
		if (v1[i].val <= cnt)
		{
			if (q == -1)
			{
				q = i;
				aux = v1[i].aux;
			}
			if (aux < v1[i].aux)
			{
				q = i;
				aux = v1[i].aux;
			}
		}
	}
	return q;
}

int pega2()
{
	int i;
	for (i=0; i<n; i++)
	{
		if (foi2[v2[i].id])
			continue;
		if (v2[i].val <= cnt)
			return i;
		return -1;
	}
	return -1;
}



int main()
{
	int i, passos, casos, cas;
	int tmp;
	
	scanf("%d",&casos);
	
	for (cas = 1; cas<= casos; cas++)
	{


		printf("Case #%d: ", cas);
		
		scanf("%d", &n);


		for (i=0; i<n; i++)
		{
			scanf("%d %d", &v1[i].val, &v2[i].val);
			v1[i].aux = v2[i].val;
			v2[i].aux = v1[i].val;
			foi1[i] = foi2[i] = 0;
			v1[i].id = v2[i].id = i;
		}
		
		qsort(v1, n, sizeof(v1[0]), fc1);
		qsort(v2, n, sizeof(v2[0]), fc2);
		
		cnt = passos = 0;
		
		while (cnt != 2*n)
		{
		/*	printf("\n[p= %d, estrelas = %d]", passos, cnt);*/
			passos++;
			tmp = pega2();
			if (tmp<0)
			{
				tmp = pega1();
				if (tmp<0)
					break;
				foi1[v1[tmp].id] = 1;
				cnt++;
			}
			else
			{
			/*	printf("\npegou %d %d", v2[tmp].aux, v2[tmp].val);*/
				if (foi1[v2[tmp].id] != 1)
				{
					cnt++;				
					foi1[v2[tmp].id] = 1;
				}
				foi2[v2[tmp].id] = 1;
				cnt++;
			}
			
		}
		if (cnt != 2*n)
		{
			printf("Too Bad\n");
		}
		else
		{
			printf("%d\n", passos);
		}
	}
	
	return 0;
	
}
