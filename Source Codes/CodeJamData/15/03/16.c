#include <stdio.h>
#include <stdlib.h>

#define MAXL 10000

typedef enum {Q1, Qi, Qj, Qk, Q_1, Q_i, Q_j, Q_k} Quar;
Quar mtable[8][8]={
	{Q1, Qi, Qj, Qk, Q_1, Q_i, Q_j, Q_k},
	{Qi, Q_1, Qk, Q_j, Q_i, Q1, Q_k, Qj},
	{Qj, Q_k, Q_1, Qi, Q_j, Qk, Q1, Q_i},
	{Qk, Qj, Q_i, Q_1, Q_k, Q_j, Qi, Q1},
	{Q_1, Q_i, Q_j, Q_k, Q1, Qi, Qj, Qk},
	{Q_i, Q1, Q_k, Qj, Qi, Q_1, Qk, Q_j},
	{Q_j, Qk, Q1, Q_i, Qj, Q_k, Q_1, Qi},
	{Q_k, Q_j, Qi, Q1, Qk, Qj, Q_i, Q_1}};

Quar Qinv(Quar x)
{
	if(x==Q1 || x==Q_1)
		return x;
	else
		return mtable[Q_1][x];
}

int main()
{
	int T,tcase,L,count,pos,forwardFirstOcc[8],backwardFirstOcc[8];
	int answer, i_blocks, k_blocks, first_i_offset, first_k_offset;
	long long X;
	Quar buffer[MAXL+1],forward[MAXL+1],backward[MAXL+1],tQ,B,x;
	unsigned char ch;


	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&L);
		scanf("%lld",&X);
		count=0;
		for(tQ=Q1;tQ<=Q_k;tQ++)
		{
			forwardFirstOcc[tQ]=-1;
			backwardFirstOcc[tQ]=-1;
		}
		while(count<L)
		{
			ch = getchar();
			switch(ch)
			{
				case 'i':
					buffer[count++] = Qi;
					break;
				case 'j':
					buffer[count++] = Qj;
					break;
				case 'k':
					buffer[count++] = Qk;
					break;
				default:
					break;
			}
		}
		forward[0]=buffer[0];
		forwardFirstOcc[forward[0]] = 0;
		for(pos=1;pos<L;pos++)
		{
			forward[pos]=mtable[forward[pos-1]][buffer[pos]];
			if(forwardFirstOcc[forward[pos]] < 0)
				forwardFirstOcc[forward[pos]] = pos;
		}
		backward[L-1]=buffer[L-1];
		backwardFirstOcc[backward[L-1]] = L-1;
		for(pos=L-2;pos>=0;pos--)
		{
			backward[pos]=mtable[buffer[pos]][backward[pos+1]];
			if(backwardFirstOcc[backward[pos]] < 0)
				backwardFirstOcc[backward[pos]] = pos;
		}
		answer=0;
		for(i_blocks=0, B=Q1; i_blocks<4; i_blocks++, B=mtable[B][forward[L-1]])
		{
			x=mtable[Qinv(B)][Qi];
			if(forwardFirstOcc[x] >= 0)
			{
				first_i_offset = forwardFirstOcc[x];
				break;
			}
		}
		if(i_blocks >= 4)
			goto PrintOutput;

		for(k_blocks=0, B=Q1; k_blocks<4; k_blocks++, B=mtable[B][forward[L-1]])
		{
			x=mtable[Qk][Qinv(B)];
			if(backwardFirstOcc[x] >= 0)
			{
				first_k_offset = backwardFirstOcc[x];
				break;
			}
		}
		if(k_blocks >= 4)
			goto PrintOutput;

		X -= i_blocks + k_blocks + 1;

		if(X < 0)
			goto PrintOutput;

		if(X == 0)
		{
			if(first_i_offset + 1 >= first_k_offset)
				goto PrintOutput;
			answer = (mtable[Q_i][forward[first_k_offset-1]] == Qj);
		}
		else
		{
			X--;
			X = X%4;
			if(first_i_offset < L-1)
				tQ = backward[first_i_offset+1];
			else
				tQ = Q1;
			while(X > 0)
			{
				tQ = mtable[tQ][forward[L-1]];
				X--;
			}
			if(first_k_offset > 0)
				tQ = mtable[tQ][forward[first_k_offset-1]];

			answer = (tQ == Qj);
		}

PrintOutput:
		printf("Case #%d: %s\n",tcase,answer?"YES":"NO");
	}

	return 0;
}

