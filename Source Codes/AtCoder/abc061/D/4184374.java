import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int n=scanner.nextInt();
		int m=scanner.nextInt();
		int[] a=new int[m];
		int[] b=new int[m];
		int[] c=new int[m];
		V=n;
		E=m;
		d=new long[V];
		edges=new Edge[E];
		Arrays.fill(d, INF);
		for(int i=0;i<m;i++) {
			a[i]=scanner.nextInt()-1;
			b[i]=scanner.nextInt()-1;
			c[i]=scanner.nextInt();
			edges[i]=new Edge(a[i],b[i],-c[i]);
		}
		if(!bellman_ford(0)) {
			System.out.println("inf");
		}else {
			System.out.println(-d[n-1]);
		}
	}
	static int V;
	static int E;
	static long[] d;	//???????????
	static Edge[] edges;
	static long INF=Long.MAX_VALUE/2;
	static boolean bellman_ford(int sv	/*???????*/) {
		d[sv]=0;
		for(int cnt=0;cnt<V;cnt++) {
			for(int i=0;i<E;i++) {
				int v=edges[i].to;
				int u=edges[i].from;
				long c=edges[i].cost;
				if(d[u]+c<d[v]) {
					d[v]=d[u]+c;
					if(cnt==V-1&&v==V-1) {
						return false;
					}
				}
			}
		}
		return true;
	}
}

class Edge{
	int from,to,cost;
	Edge(int from,int to,int cost){
		this.from=from;
		this.to=to;
		this.cost=cost;
	}
}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}