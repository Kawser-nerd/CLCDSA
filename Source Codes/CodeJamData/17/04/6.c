#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define F1(i,n) for(int i=1;i<=n;i++)
#define F0(i,n) for(int i=0;i<n;i++)

int countEmptyDiags(unsigned int *M, int r, int c, int R,int C){
	int num = 0;
	if(r >= c){
		int _r = r - c;
		int _c = 0;
		while(_r < R && _c < C){
			if((M[_r*C+_c] & 0xf0) == 0){
				num++;
			}
			_r++;
			_c++;
		}
	}else{
		int _r = 0;
		int _c = c-r;
		while(_r < R && _c < C){
			if((M[_r*C+_c] & 0xf0) == 0){
				num++;
			}	
			_r++;
			_c++;
		}
	}
	if(r+c < C){
		int _r = 0;
		int _c = c+r;
		while(_c >= 0 && _r < R){
			if((M[_r*C+_c] & 0xf0) == 0){
				num++;
			}	
			_r++;
			_c--;
		}
	}else{
		int _r = r - (C-c);
		int _c = C-1;
		while(_c >= 0 && _r < R){
			if((M[_r*C+_c] & 0xf0) == 0){
				num++;
			}
			_r++;
			_c--;
		}
	}
	return num;
}

void fillDiags(unsigned int *M,int r,int c, int R, int C,unsigned int val){
	// fill up SE diag
	if(r >= c){
		int _r = r - c;
		int _c = 0;
		while(_r < R && _c < C){
			M[_r*C + _c] |= val;
			_r++;
			_c++;
		}
	}else{
		int _r = 0;
		int _c = c-r;
		while(_r < R && _c < C){
			M[_r*C + _c] |= val;
			_r++;
			_c++;
		}
	}
	if(r+c < C){
		int _r = 0;
		int _c = c+r;
		while(_c >= 0 && _r < R){
			M[_r*C + _c] |= val;
			_r++;
			_c--;
		}
	}else{
		int _r = r - (C-c);
		int _c = C-1;
		while(_c >= 0 && _r < R){
			M[_r*C + _c] |= val;
			_r++;
			_c--;
		}
	}
}

int getMin(unsigned int *M,int R, int C,int *r, int *c){
	int m = 0;
	F0(_r,R)F0(_c,C){
		if((M[_r*C+_c] & 0xf0) == 0){
			int count = countEmptyDiags(M,_r,_c,R,C)-1;
			if(m==0 || count < m){
				(*r) = _r;
				(*c) = _c;
				m = count;
			}
		}
	}
	return m;
}

int main(){
	int T,N,M;
	unsigned int* G = malloc(100*100*sizeof(unsigned int));
	scanf("%d\n",&T);
	F1(i,T){
		printf("Case #%d: ",i);
		scanf("%d %d\n",&N,&M);
		memset(G,0,100*100*sizeof(unsigned int));
		F0(j,M){
			int r,c;
			char t;
			scanf("%c %d %d\n",&t,&r,&c);
			r -= 1;
			c -= 1;
			if(t == 'x' || t=='o'){
				G[r*N + c] |= 1<<0;
				F0(k,N)G[k*N + c] |= 1<<1;
				F0(k,N)G[r*N + k] |= 1<<1;
			}
			if(t == '+' || t=='o'){
				G[r*N + c] |= 1<<4;
				fillDiags(G,r,c,N,N,1<<5);
			}
		}
		//printf("\ninput:\n");
		//F0(_r,N){F0(_c,N){printf("%02X|",G[_r*N+_c]);}printf("\n");}
		// fill up MX
		F0(r,N){
			F0(c,N){
				if((G[r*N + c] & 0xf) == 0){
					//printf("\nPutting X on (%d,%d)\n",r+1,c+1);
					G[r*N + c] |= 1<<2;
					F0(k,N)G[k*N + c] |= 1<<3;
					F0(k,N)G[r*N + k] |= 1<<3;
					break;
				}				
			}
		}
		// fill up MP
		F0(j,N)if((G[j] & 1<<4) == 0)G[j] |= 1<<6;
		for(int j=1;j<N-1;j++)G[(N-1)*N + j] |= 1<<6;
		//int r,c,m;
		//while(m = getMin(G,N,N,&r,&c)){
		//	G[r*N+c] |= 1<<6;
		//	fillDiags(G,r,c,N,N,1<<7);
		//}
		//printf("\noutput:\n");
		//F0(_r,N){F0(_c,N){printf("%02X|",G[_r*N+_c]);}printf("\n");}
		int numOfMod = 0;
		int points = 0;
		F0(r,N)F0(c,N){
			// check if we put down either 'X' or '+'
			if(G[r*N+c] & (1<<6) || G[r*N+c] & (1<<2)){
				numOfMod++;
			}
			int X = G[r*N+c] & (1<<0 | 1<<2);
			int P = G[r*N+c] & (1<<4 | 1<<6);
			if(X && P)points+=2;
			else if(X)points++;
			else if(P)points++;
			
		}
		printf("%d %d\n",points,numOfMod);	
		F0(r,N)F0(c,N){
			// check if we put down either 'X' or '+'
			if(G[r*N+c] & (1<<6) || G[r*N+c] & (1<<2)){
				int X = G[r*N+c] & (1<<0 | 1<<2);
				int P = G[r*N+c] & (1<<4 | 1<<6);
				if(X && P)printf("o %d %d\n",r+1,c+1);
				else if(X)printf("x %d %d\n",r+1,c+1);
				else if(P)printf("+ %d %d\n",r+1,c+1);
				else{
					fprintf(stderr,"Not supposed to reach this\n");
					return 1;
				}
			}
		}
	}		
}
