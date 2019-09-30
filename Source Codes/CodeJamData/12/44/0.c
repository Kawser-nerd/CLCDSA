#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

int x,y;
char s[64][64];

int calc64(int atx,int aty) {
	atx--;
	aty--;
	return atx+aty*(x-2);
}

int dy[]={1,-1,0},dx[]={0,0,-1};
ull count(int atx,int aty) {
	static char v[64][64];
	static int q[8192];
	int qs=0,qe=0,cx,cy,x2,y2,d;
	ull mask=0;
	memset(v,0,sizeof(v));
	v[atx][aty]=1;
	mask|=1ULL<<calc64(atx,aty);
	q[qe++]=atx; q[qe++]=aty;
	while(qs<qe) {
		cx=q[qs++]; cy=q[qs++];
		for(d=0;d<3;d++) {
			x2=cx+dx[d]; y2=cy+dy[d];
			if(s[x2][y2]=='#') continue;
			if(v[x2][y2]) continue;
			mask|=1ULL<<calc64(x2,y2);
			q[qe++]=x2; q[qe++]=y2;
			v[x2][y2]=1;
		}
	}
	return mask;
}

int bc(ull mask) {
	int i,r=0;
	for(i=0;i<64;i++) if(mask&(1ULL<<i)) r++;
	return r;
}

typedef long long ll;
typedef unsigned char uchar;

#define MAXHASH 100000007
int maxhash=MAXHASH;

uchar hash[(MAXHASH+7)/8];  /*  bit i set if element i is taken */
ull hashdata[MAXHASH];

#define GETHASH(key) key%maxhash
#define HASHBIT(pos) (hash[pos>>3]&(1<<(pos&7)))

int exists(ull key) {
	int pos=GETHASH(key);
	while(1) {
    if(!HASHBIT(pos)) return 0;
    if(hashdata[pos]==key) return 1;
    pos++; if(pos==maxhash) pos=0;
	}
}
int gethashpos(ull key) {
  int pos=GETHASH(key);
  while(1) {
    if(!HASHBIT(pos)) break;
    if(hashdata[pos]==key) break;
    pos++; if(pos==maxhash) pos=0;
  }
  return pos;
}
void puthash(ull key) {
  int pos=gethashpos(key);
  hash[pos>>3]|=1<<(pos&7);
  hashdata[pos]=key;
}
void inithashdata() {
  memset(hash,0,sizeof(hash));
}

ull q[100000000];
int qs,qe;

int bfs(int cave,ull start) {
	ull cur,next,goal=0;
	int d,i,j,b,k,l;
	for(i=0;i<x;i++) for(j=0;j<y;j++) if(cave+48==s[i][j]) goal=1ULL<<calc64(i,j);
	if(start==goal) return 1;
	qs=qe=0;
//	printf("cave %d goal %I64u\n",cave,goal);
	inithashdata();
	q[qe++]=start;
	puthash(start);
	while(qs<qe) {
		cur=q[qs++];
//		printf("pop %I64u\n",cur);
		for(d=0;d<3;d++) {
			next=0;
			for(b=0;b<64;b++) if(cur&(1ULL<<b)) {
				k=i=1+b%(x-2);
				l=j=1+b/(x-2);
				if(d==0) l--;
				else if(d==1) l++;
				else if(d==2) k++;
				if(s[k][l]=='#') k=i,l=j;
				next|=1Ull<<calc64(k,l);
			}
//			printf("  dir %d, visit %I64u\n",d,next);
			if((~start)&next) continue;
			if(exists(next)) continue;
			if(next==goal) return 1;
//			printf("  push %I64u\n",next);
			q[qe++]=next;
			puthash(next);
		}
	}
	return 0;
}

int main() {
	int cases,caseno=1,i,j,cave,r;
	ull mask;
	scanf("%d",&cases);
	while(cases--) {
		scanf("%d %d",&x,&y);
		for(i=0;i<x;i++) scanf("%s",s[i]);
		printf("Case #%d:\n",caseno++);
		for(cave=0;cave<10;cave++) {
			for(i=0;i<x;i++) for(j=0;j<y;j++) if(s[i][j]==48+cave) goto found;
			continue;
		found:
			mask=count(i,j);
			r=bfs(cave,mask);
			printf("%d: %d %s\n",cave,bc(mask),r?"Lucky":"Unlucky");
		}
	}
	return 0;
}
