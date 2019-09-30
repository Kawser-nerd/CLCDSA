#include <stdio.h>

/* min-heap! warning, 1-indexed, index 0 is unused */
/* heapn starts at 1 (number of elements is 0, +1) */

#define MAXH 1000500

long long heap[MAXH];   /* heap value (on which it is sorted)  */
long long heapid[MAXH]; /* heap id */
int heapn;        /* (number of elements in heap)+1 */

/* insert a new value to the heap */
/* warning, function will choke if heap is full */
void heapinsert(long long val,long long id) {
	int pos=heapn++;
	/* change to val> for maxheap */
	while(pos>1 && val>heap[pos>>1]) {
		heap[pos]=heap[pos>>1];
		heapid[pos]=heapid[pos>>1];
		pos>>=1;
	}
	heap[pos]=val; heapid[pos]=id;
}

/* remove a value from the heap and put it in *val,*id */
/* don't call if heap is empty! */
void heapremove(long long *val,long long *id) {
	int pos=1,next=1;
	long long newval;
	long long newid;
	*val=heap[1]; *id=heapid[1];
	newval=heap[--heapn];
	newid=heapid[heapn];
	while((pos<<1)<=heapn) {
		/* take lowest of left and right children */
		if((pos<<1)==heapn) next=pos<<1;
		/* change to <heap[...] for maxheap */
		else next=(pos<<1)+(heap[pos<<1]<heap[(pos<<1)+1]);
		/* change to <=newval for maxheap */
		if(heap[next]<=newval) break;
		heap[pos]=heap[next];
		heapid[pos]=heapid[next];
		pos=next;
	}
	heap[pos]=newval;
	heapid[pos]=newid;
}

void solve() {
	long long n,k;
	long long val,antall;
	long long v1,v2;
	int i;
	scanf("%I64d %I64d",&n,&k);
	heapn=1;
	heapinsert(n,1);
	while(1) {
		heapremove(&val,&antall);
		v1=val/2;
		v2=(val-1)/2;
//		printf("%I64d (%I64d) => %I64d %I64d left %I64d\n",val,antall,v1,v2,k);
		if(antall>=k) {
			printf("%I64d %I64d\n",v1,v2);
			return;
		}
		for(i=1;i<heapn;i++) if(heap[i]==v1) { heapid[i]+=antall; break; }
		if(i==heapn) heapinsert(v1,antall);
		for(i=1;i<heapn;i++) if(heap[i]==v2) { heapid[i]+=antall; break; }
		if(i==heapn) heapinsert(v2,antall);
		k-=antall;
	}
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
