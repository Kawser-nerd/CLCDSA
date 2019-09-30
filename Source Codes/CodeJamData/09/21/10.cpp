#include<cstdio>
#include<string>
#include<map>

using namespace std;

map<string,int> fno;

int cfeat;

struct tree{
	double p;
	int feature;
	tree *l,*r;
};

void getopening(){
	char c = getchar();;
	while(true){
		if( c == '(') return;
		c = getchar();
	}
}

char getclosing(){
	char c = getchar();
	while(true){
		if(c == ')') return ')';
		else if(c>='a' && c<='z') return c;
		c = getchar();
	}
}

char s[100];

tree* readtree(){
	tree* tr = new tree;
	getopening();
	scanf("%lf",&tr->p);
	char c = getclosing();
	if(c == ')'){
		tr->feature = -1;
		return tr;
	}else{
		string s = "";
		while(c>='a' && c<='z'){
			s = s + c;
			c = getchar();
		}
		if(fno.find(s) == fno.end()) fno[s] = ++cfeat;
		tr->feature = fno[s];
		tr->l = readtree();
		tr->r = readtree();
		getclosing();
		return tr;
	}
}

void printtree(tree* tr,int lev){
	for(int i=0;i<lev;i++) printf("  ");
	printf("%lf",tr->p);
	if(tr->feature == -1){
		printf("\n");
		return;
	}else{
		printf(" %d\n",tr->feature);
		printtree(tr->l,lev+1);
		printtree(tr->r,lev+1);
	}
}

void del(tree* tr){
	if(tr->feature != -1){
		del(tr->l);
		del(tr->r);
	}
	delete tr;
}


bool got[1005];

double prob(tree* tr){
	if(tr->feature == -1) return tr->p;
	else if(got[tr->feature]) return tr->p * prob(tr->l);
	else return tr->p * prob(tr->r);
}

int main(){
	int d;
	scanf("%d",&d);
	for(int i=1;i<=d;i++){
		printf("Case #%d:\n",i);
		scanf("%*d");
		tree* root = readtree();
		int m;
		scanf("%d",&m);
		while(m--){
			for(int i=1;i<=cfeat;i++) got[i] = 0;
			scanf("%*s");
			int cf;
			scanf("%d",&cf);
			while(cf--){
				scanf("%s",s);
				string ss(s);
				if(fno.find(ss) == fno.end()) continue;
				else got[fno[ss]] = 1;
			}
			printf("%.7lf\n",prob(root));
		}
		del(root);
		cfeat = 0;
		fno.clear();
	}
}
