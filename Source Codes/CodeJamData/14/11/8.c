#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/*
int my_cmp(const void *a, const void *b){
	int i;
	bool* ba = (bool*)a;
	bool* bb = (bool*)b;
	for(i=0; i<l; i++){
		bool va = ba[i];
		bool vb = bb[i];
		if(!va && vb) return -1;
		else if(va && !vb) return 1;
	}
	return 0;
}
/*
int checkswap(int lcurr, int hstart, int wstart, int len){
	if(lcurr == l) return 0;
	int i;
	int hoff = 0, hon=0, woff=0, won=0;
	
	for(i = 0; i < len; i++){
		if(have[hstart+i][lcurr]) hon++;
		else hoff++;
		
		if(want[wstart+i][lcurr]) won++;
		else woff++;
	}
	
	if(hoff == won){
		if(hoff == woff){
			return 1;
		} else {
			return 2;
		}
	} else if(hoff == woff){
		return 0;
	} else {
		return -1;
	}
}
*/

struct hash_rec{
	uint64_t val;
	int count;
	struct hash_rec *next;
};

#define TAB_SIZE 10007
#define NULL_ANS 0xFFFFFFFFFFFFFFFF
struct hash_rec* tab[TAB_SIZE];
int best;

void free_rec(struct hash_rec* r){
	if(r != NULL) free_rec(r->next);
	free(r);
}

void check_new_best(uint64_t val){
	int rank = 0;
	int test = val;
	while(test != 0){
		if(test&1) rank++;
		test = test >> 1;
	}
	if(best == -1 || rank < best) best=rank;
}

void add_hash(uint64_t val, int n){
	int hash = (11*val)%TAB_SIZE;
	struct hash_rec *curr = tab[hash];
	if(curr == NULL){
		struct hash_rec *r = malloc(sizeof(struct hash_rec));
		r->val = val;
		r->count=1;
		r->next = NULL;
		tab[hash] = r;
		if(n == 1) check_new_best(val);
		return;
	}
	
	struct hash_rec *prev;
	do{
		if(curr->val == val){
			int c = curr->count;
			c++;
			curr->count = c;
			if(c == n){
				check_new_best(val);
			}
			return;
		}
		prev = curr;
		curr = curr->next;
	} while(curr != NULL);
	struct hash_rec *r = malloc(sizeof(struct hash_rec));
	r->val = val;
	r->count=1;
	r->next = NULL;
	prev->next = r;
	if(n == 1) check_new_best(val);
	return;
}

int go(void){
	int n,l;
	scanf("%d %d",&n,&l);
	uint64_t have[n];
	uint64_t want[n];
	int i,j;
	for(i=0; i<n; i++){
		uint64_t temp = 0;
		for(j=0; j<l; j++){
			char c;
			do{
				scanf("%c",&c);
			} while(c != '0' && c != '1');
			temp = (temp << 1) | (c == '1');
		}
		have[i] = temp;
	}
	for(i=0; i<n; i++){
		uint64_t temp = 0;
		for(j=0; j<l; j++){
			char c;
			do{
				scanf("%c",&c);
			} while(c != '0' && c != '1');
			temp = (temp << 1) | (c == '1');
		}
		want[i] = temp;
	}

	//	qsort(have,n,sizeof(void*),mp_cmp);
//	qsort(want,n,sizeof(void*),mp_cmp);
	
	for(i=0; i<TAB_SIZE; i++){
		free_rec(tab[i]);
		tab[i] = NULL;
	}
	best = -1;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			uint64_t val = have[i] ^ want[j];
//			printf("DEBUG: 0x%016x ^ 0x%016x = 0x%016x\n",have[i],want[j],val); 
			add_hash(val,n);
		}
	}
	return best;
}

int main(int argc, char** argv){
	int t;
	scanf("%d",&t);
	int i;
	for(i=1; i<=t; i++){
		int ans = go();
		printf("Case #%d: ",i);
		switch(ans){
		case -1:
			printf("NOT POSSIBLE\n");
			break;
		default:
			printf("%d\n",ans);
			break;
		}
	}
	return 0;
}
