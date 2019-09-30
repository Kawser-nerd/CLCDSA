#include <vector>
#include <iostream>
#include <string>

using namespace std;

const unsigned int M = 1000000007;

struct Node {
	unsigned int num;
	unsigned int tmp;
	Node *a, *g, *c, *t;
	Node () {
		num = tmp = 0;
	}
	void add(unsigned int n) {
		tmp += n;
		tmp %= M;
	}

	void next_gen() {
		num = tmp;
		tmp = 0;
	}
};


int main() {
	Node *root;
	Node end;
	Node *a, *ag, *agg, *agt, *ac, *at, *atg, *g, *ga;
	vector<Node> ar(10);
	root = &ar[0];
	a = &ar[1];
	ag = &ar[2];
	agg = &ar[3];
	agt = &ar[4];
	ac = &ar[5];
	at = &ar[6];
	atg = &ar[7];
	g = &ar[8];
	ga = &ar[9];

	root->a = a;
	root->g = g;
	root->c = root;
	root->t = root;

	a->a = a;
	a->g = ag;
	a->c = ac;
	a->t = at;

	ag->a = ga;
	ag->g = agg;
	ag->c = &end;
	ag->t = agt;

	agg->a = ga;
	agg->g = g;
	agg->c = &end;
	agg->t = root;

	agt->a = a;
	agt->g = g;
	agt->c = &end;
	agt->t = root;

	ac->a = a;
	ac->g = &end;
	ac->c = root;
	ac->t = root;

	at->a = a;
	at->g = atg;
	at->c = root;
	at->t = root;

	atg->a = ga;
	atg->g = g;
	atg->c = &end;
	atg->t = root;

	g->a = ga;
	g->g = g;
	g->c = root;
	g->t = root;

	ga->a = a;
	ga->g = ag;
	ga->c = &end;
	ga->t = at;

	root->num = 1;

	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(auto &x: ar) {
			x.a->add(x.num);
			x.g->add(x.num);
			x.c->add(x.num);
			x.t->add(x.num);
		}
		for(auto &x: ar) x.next_gen();
	}

	int sum = 0;
	for(auto &x: ar) {
		sum += x.num;
		sum %= M;
	}

	cout << sum << endl;
}