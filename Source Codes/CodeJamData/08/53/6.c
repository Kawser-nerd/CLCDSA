#include <stdio.h>
#include <string.h>

int max[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
char desks[12][12];
int r, c;
int f[12][1026];
int desk[12], hasdesk, deskid;
short conf[1026][1026];

int calc(int a, int b){
	int d[12];
	int i;
	memset(d, 0, sizeof(d));
	if(conf[a][b] != 0)
		return conf[a][b];
	for(i = 0; b > 0; i++){
		d[i] = b % 2;
		b /= 2;
	}
	for(i = 0; a > 0; i++){
		if(a % 2 == 1){
			if((i > 0 && d[i - 1] == 1) || d[i + 1] == 1){
				conf[a][b] = 2;
				return 2;
			}
		}
		a /= 2;
	}
	conf[a][b] = 1;
	return 1;
}

void gogo(int r){
	int i;
	for(i = 0; i < max[c]; i++){
		if(r == 0){
			f[r][deskid] = hasdesk;
		}
		else if(calc(deskid, i) == 1 && f[r][deskid] < f[r - 1][i] + hasdesk){
			f[r][deskid] = f[r - 1][i] + hasdesk;
		}
	}
}

void find(int rr, int x){
	if(x == c){
		gogo(rr);
	}
	else{
		desk[x] = 0;
		deskid *= 2;
		find(rr, x + 1);
		deskid /= 2;
		if((x == 0 || desk[x - 1] != 1) && desks[rr][x] == '.'){
			hasdesk++;
			desk[x] = 1;
			deskid = deskid * 2 + 1;
			find(rr, x + 1);
			hasdesk--;
			deskid /= 2;
		}
	}
}

int go(){
	int i;
	int ans = 0;
	scanf("%d%d", &r, &c);
	for(i = 0; i < r; i++)
		scanf("%s", desks[i]);
	memset(f, 0, sizeof(f));
	memset(desk, 0, sizeof(desk));
	deskid = hasdesk = 0;
	for(i = 0; i < r; i++){
		find(i, 0);
	}
	for(i = 0; i < max[c]; i++){
		if(ans < f[r - 1][i])
			ans = f[r - 1][i];
	}
	return ans;
}

int main(){
	int cs, i;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &cs);
	memset(conf, 0, sizeof(conf));
	for(i = 1; i <= cs; i++){
		printf("Case #%d: %d\n", i, go());
	}
	return 0;
}
