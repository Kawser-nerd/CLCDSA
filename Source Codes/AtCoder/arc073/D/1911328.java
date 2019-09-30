import java.io.*;
import java.util.*;


class Main {
    static final long I = (1L << 62) - 1;
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int q=sc.nextInt();
        int a=sc.nextInt();
        int[]x=new int[q+1];
        for(int i=0;i<=q;++i)x[i]=sc.nextInt();
        MinSegmentTree segA=new MinSegmentTree();
        MinSegmentTree segB=new MinSegmentTree();
        for(int i=1;i<=n;++i){
            long v=i==a?0:I;
            segA.update(i,v-i);
            segB.update(i,v+i);
        }
        long acc=0;
        for(int i=1;i<=q;++i){
            long diff=Math.abs(x[i]-x[i-1]);
            acc+=diff;
            long dpix=Math.min(segA.query(1,x[i])+x[i],segB.query(x[i],n+1)-x[i]);
            dpix-=diff;
            segA.update(x[i-1],dpix-x[i-1]);
            segB.update(x[i-1],dpix+x[i-1]);
            if (false) {
                out.println("st "+i);
                for(int j=1;j<10;++j){
                    long val=segA.query(j,j+1)+j;
                    if(val<I)
                        out.print(val+acc+" ");
                    else
                        out.print("inf ");
                }
                out.println();
            }
        }
        long mi=I;
        for(int i=1;i<=n;++i)
            mi=Math.min(mi,acc+segA.query(i,i+1)+i);
        out.println(mi);
        out.close();
    }
    // http://codeforces.com/blog/entry/7018
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
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