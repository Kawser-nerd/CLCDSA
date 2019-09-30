#include <stdio.h>
#include <stdlib.h>

#define integer unsigned long long int

#define affinteger "%llu"

struct arbrelistner{
	integer x;
	integer y;
	integer n;
};

struct state{
	int n, a, b, c, d, x, y, m;
};

int hasnext(struct arbrelistner *al, struct state *s){
	return al->n < s->n;
}

void next(integer *x, integer *y,
struct arbrelistner *al, struct state *s)
{
	if (al->n != 0){
		al->x=(s->a * al->x + s->b) % s->m;
		al->y=(s->c * al->y + s->d) % s->m;
	}
	*x = al->x;
	*y = al->y;
	al->n++;
}
void newal(struct arbrelistner *al, struct state *s){
	al->x=s->x;
	al->y=s->y;
	al->n=0;
}

int count(struct state *s){
	struct arbrelistner al1, al2, al3;
	integer x1, y1, x2, y2, x3, y3;
	int count=0;
	newal(&al1, s);
	while (hasnext(&al1, s)){
		next(&x1, &y1, &al1, s);
		//printf("%d, %d\n", x1, y1);
		newal(&al2, s);
		while (hasnext(&al2, s)){
			next(&x2, &y2, &al2, s);
			if (al2.n <= al1.n) continue;
			//printf("\t%d, %d\n", x2, y2);
			newal(&al3, s);
			while (hasnext(&al3, s)){
				next(&x3, &y3, &al3, s);
				if (al3.n <= al2.n) continue;
				//printf("\t\t%d, %d\n", x3, y3);
				if (
				(x1 + x2 + x3) % 3 == 0 &&
				(y1 + y2 + y3) % 3 == 0 ) count++;
			}
		}
	}
	return count;
}

int count2(struct state *s){
	integer *x, *y;
	int i, j, k;
	int count;
	struct arbrelistner al;
	x=malloc(s->n * sizeof(integer));
	y=malloc(s->n * sizeof(integer));
	newal(&al, s);
	i=0;
	while (hasnext(&al, s)){
		next(x+i, y+i, &al, s);
		i++;
	}
	count = 0;
	for (i=0;i<s->n;i++)
	for (j=i+1;j<s->n;j++)
	for (k=j+1;k<s->n;k++){
		if (
		(x[i] + x[j] + x[k]) % 3 == 0 &&
		(y[i] + y[j] + y[k]) % 3 == 0 ) count++;
	}
	return count;
}

void solve(){
	int i;
	struct state s;
	scanf("%d %d %d %d %d %d %d %d\n",
		&s.n, &s.a, &s.b, &s.c, &s.d, &s.x, &s.y, &s.m);
	printf(affinteger, count(&s));
}

int main(){
	int i, n;
	scanf("%d\n", &n);
	for (i=0;i<n;i++){
		printf("Case #%d: ", i+1);
		solve();
		putchar('\n');
	}
}
