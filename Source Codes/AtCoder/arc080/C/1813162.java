import java.util.*;

class A implements Comparable<A>{
    long v;
    int l,r;
    A(long v,int l,int r){
        this.v=v;
        this.l=l;
        this.r=r;
    }
    @Override
    public int compareTo(A o){
        return Long.compare(v,o.v);
    }
    @Override
    public String toString(){
        return v+":"+l+"-"+r;
    }
}

class Main {
    static final boolean DEBUG=false;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n=scan.nextInt();
        int[]p=new int[n];
        for(int i=0;i<n;++i)p[i]=Integer.parseInt(scan.next());
        MinSegmentTree m0=new MinSegmentTree();
        MinSegmentTree m1=new MinSegmentTree();
        Queue<A> q=new PriorityQueue<A>();
        for(int i=0;i<n/2;++i){
            m0.update(i,(long)p[2*i]<<32|i);
            m1.update(i,(long)p[2*i+1]<<32|i);
        }
        long[]ans=new long[n];
        int ansp=0;
        q.add(new A(m0.query(0,n/2),0,n));
        while(q.size()>0){
            if (DEBUG){
                System.err.println("que="+q);
            }
            A t=q.poll();
            long v=t.v;
            int l=t.l;
            int r=t.r;
            int fi=(int)v;
            if(l%2==0)
                fi=fi*2;
            else
                fi=fi*2+1;
            if(l>=r)continue;
            long s;
            if(l%2==0)
                s=m1.query(fi/2,r/2);
            else
                s=m0.query(fi/2+1,r/2+1);
            ans[ansp]=v>>>32;
            ans[ansp+1]=s>>>32;
            ansp+=2;
            int si=(int)s;
            if(l%2==0){
                si=si*2+1;
            }else{
                si=si*2;
            }
            if(DEBUG){
                System.err.println("ans:"+ans[ansp-2]+" "+ans[ansp-1]);
                System.err.println("fi="+fi+" si="+si);
            }
            if(l<fi)
                q.add(new A((l%2==0?m0:m1).query(l/2,fi/2),l,fi));
            if(fi+1<si)
                q.add(new A((l%2==0?m1:m0).query((fi+1)/2,si/2),fi+1,si));
            if(si+1<r)
                q.add(new A((l%2==0?m0:m1).query((si+1)/2,r/2),si+1,r));
        }
        for(int i=0;i<n;++i)
            System.out.print(ans[i]+(i==n-1?"\n":" "));
    }
}
class MinSegmentTree {
    static final int SIZE = 1 << 18;
    static final long INFINITY = (1L << 62) - 1;
    long[] seg;
    MinSegmentTree() {
	this.seg = new long[2 * SIZE];
    }
    void update(int x, long value) {
	x += SIZE - 1;
	this.seg[x] = value;
	while (x > 0) {
	    x = (x - 1) / 2;
	    this.seg[x] = Math.min(this.seg[2 * x + 1], this.seg[2 * x + 2]);
	}
    }
    long query(int l, int r) {
	l += SIZE - 1;
	r += SIZE - 1;
        long y = INFINITY;
	while (l < r) {
	    if ((l & 1) == 0) {
		y = Math.min(y, this.seg[l]);
	    }
	    if ((r & 1) == 0) {
		y = Math.min(y, this.seg[r - 1]);
	    }
	    l /= 2;
	    r = (r - 1) / 2;
	}
	return y;
    }
}