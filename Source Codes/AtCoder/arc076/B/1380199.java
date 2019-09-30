import java.io.IOException;
import java.io.InputStream;
import java.util.*;
 
public class Main{
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		long[][] mati = new long[N][3];
		for(int i=0; i<N; ++i){
			mati[i][0] = sc.nextLong();
			mati[i][1] = sc.nextLong();
			mati[i][2] = i;
		}
		
		long[][] edge = new long[2*(N-1)][3];
		int p = 0;
		quickSort(mati,0,0,N);
		for(int i=1;i<N;++i){
			edge[p][0] = mati[i][2];
			edge[p][1] = mati[i-1][2];
			edge[p][2] = (mati[i][0]-mati[i-1][0]);
			p++;
		}
		quickSort(mati,1,0,N);
		for(int i=1;i<N;++i){
			edge[p][0] = mati[i][2];
			edge[p][1] = mati[i-1][2];
			edge[p][2] = (mati[i][1]-mati[i-1][1]);
			p++;
		}
		quickSort(edge,2,0,2*(N-1));
		
		long ans = kruskal(edge,N);
		System.out.println(ans);
		return;
	}
	
	public static long kruskal(long[][] e,int num){
		int[] parent = new int[num];
		int[] rank = new int[num];
		for(int i=0; i<num; ++i){
			parent[i] = i; rank[i] = 0;
		}
		long min_cost = 0;
		
		for(int i=0; i<e.length; ++i){
			int xRoot = find((int)e[i][0],parent);
			int yRoot = find((int)e[i][1],parent);
			if( xRoot!=yRoot ){
				min_cost += e[i][2];
				if(rank[xRoot]>rank[yRoot]){
					parent[yRoot]=xRoot;
				}else if(rank[xRoot]<rank[yRoot]){
					parent[xRoot]=yRoot;
				}else{
					parent[yRoot]=xRoot;
					rank[xRoot]++;
				}
			}
		}
		return min_cost;
	}
	
	public static int find(int x, int[] parent){
		return x==parent[x] ? x : find(parent[x],parent);
	}
	
	public static void quickSort(long[][] a, int index, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		long x = a[from + (new Random()).nextInt(to - from)][index];
		while (i <= j) {
			while (a[i][index] < x) {
				i++;
			}
			while (a[j][index] > x) {
				j--;
			}
			if (i <= j) {
				for(int k=0; k<3; k++){
					long t = a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = t;
				}
				i++;
				j--;
			}
		}
		quickSort(a, index, from, j + 1);
		quickSort(a, index, j + 1, to);
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