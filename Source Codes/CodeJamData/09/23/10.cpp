#include<cstdio>
#include<algorithm>

using namespace std;

const int AD = 2500;

struct state{
	int p;
	int num;
	char sign;
	char digit;
	int y,x;
	int eqclass;
	int sum;
};

bool vis[5000][25][25];

char square[25][25];

int n,cq;

int dx1[] = {-1,1,-1,1,0,0,0,0,1,-1,0,0,1,-1,0,0};
int dy1[] = {0,0,0,0,-1,1,-1,1,0,0,1,-1,0,0,1,-1};
int dx2[] = {0,0,0,0,-1,1,1,-1,-1,1,0,0,1,-1,0,0};
int dy2[] = {-1,1,1,-1,0,0,0,0,0,0,-1,1,0,0,1,-1};

bool ok(int y,int x){
	return y>=1 && y<=n && x>=1 && x<=n;
}

bool isq[255];
int answ[255];
int needed;

state q[1000005];
int qh,qt;

void add_state(state c){
	if(vis[c.sum + AD][c.y][c.x]) return;
	if(c.sum>=1 && c.sum<=250 && isq[c.sum]){
		isq[c.sum]  = 0;
		answ[c.sum] = qt + 1;
		--needed;
	}
	c.num = qt+1;
	vis[c.sum + AD][c.y][c.x] = 1;
	q[++qt] = c;
}

state s[1000005];
int ss;

void add_neighbours(state c){
	for(int i=0;i<16;i++){
		if(!ok(c.y + dy1[i] + dy2[i], c.x + dx1[i] + dx2[i])) continue;
		if(!ok(c.y + dy1[i], c.x + dx1[i])) continue;
		++ss;
		s[ss].p = c.num;
		s[ss].sign = square[c.y + dy1[i]][c.x + dx1[i]];
		s[ss].digit = square[c.y + dy1[i] + dy2[i]][c.x + dx1[i] + dx2[i]];
		if(s[ss].sign == '+') s[ss].sum = c.sum + int(s[ss].digit - '0');
		else s[ss].sum = c.sum - int(s[ss].digit - '0');
		s[ss].y = c.y + dy1[i] + dy2[i];
		s[ss].x = c.x + dx1[i] + dx2[i];
		if(abs(s[ss].sum) > 2000) --ss;
	}
}

bool operator < (state a,state b){
	if(q[a.p].eqclass != q[b.p].eqclass) return q[a.p].eqclass < q[b.p].eqclass;
	if(a.sign != b.sign) return a.sign < b.sign;
	return a.digit < b.digit;
}

int queries[255];

void printpath(int x){
	if(q[x].p == 0){
		printf("%c",q[x].digit);
	}else{
		printpath(q[x].p);
		printf("%c%c",q[x].sign,q[x].digit);
	}
}

int mx = 0;

void alg(int tno){
	for(int i=1;i<=250;i++) isq[i] = 0;
	printf("Case #%d:\n",tno);
	scanf("%d%d",&n,&cq);
	qh = qt = ss = 0;
	for(int i=0;i<5000;i++) for(int y=1;y<=n;y++) for(int x=1;x<=n;x++) vis[i][y][x] = 0;
	for(int i=1;i<=n;i++) scanf("%s",square[i]+1);
	for(int i=1;i<=cq;i++){
		scanf("%d",&queries[i]);
		isq[queries[i]] = 1;
	}
	needed = cq;
	q[0].eqclass = 0;
	q[0].sign = '+';
	q[0].digit = '0' - 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(square[i][j] >= '0' && square[i][j] <= '9'){
				++ss;
				s[ss].p = 0;
				s[ss].digit = square[i][j];
				s[ss].sign = '+';
				s[ss].sum = s[ss].digit - '0';
				s[ss].y = i;
				s[ss].x = j;
			}
		}
	}
	sort(s+1,s+ss+1);
	for(int i=1;i<=ss;i++)
		add_state(s[i]);
	ss = 0;
	for(qh=1;qh<=qt;qh++ && needed){
		if(q[qh-1] < q[qh]){
			sort(s+1,s+ss+1);
			for(int i=1;i<=ss;i++)
				add_state(s[i]);
			ss = 0;
			q[qh].eqclass = q[qh-1].eqclass + 1;
		}else q[qh].eqclass = q[qh-1].eqclass;
		add_neighbours(q[qh]);
	}
	mx = max(mx,qt);
	for(int i=1;i<=cq;i++){
		printpath(answ[queries[i]]);
		printf("\n");
	}
}

int main(){
	int d;
	scanf("%d",&d);
	for(int i=1;i<=d;i++) alg(i);
}
