import java.util.Map.Entry;
import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int N = sc.nextInt();
		long[][] cost = new long[N][N];
		for(long[] c : cost) Arrays.fill(c, 1001);
		int M = sc.nextInt();
		int[][] edge = new int[M][3];
		for(int i = 0; i < M; i++){
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			int c = sc.nextInt();
			cost[a][b] = c;
			cost[b][a] = c;
			edge[i][0] = a;
			edge[i][1] = b;
			edge[i][2] = c;
		}
		for(int i = 0; i < N; i++) cost[i][i] = 0;
		
		for(int k = 0; k < N; k++){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					cost[i][j] = Math.min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}
		
		int ans = 0;
		for(int k = 0; k < M; k++){
			int a = edge[k][0];
			int b = edge[k][1];
			int c = edge[k][2];
			boolean tf = false;
			for(int i = 0; i < N && !tf; i++){
				for(int j = 0; j < N && !tf; j++){
					if(cost[i][j] == cost[i][a] + c + cost[b][j]){
						tf = true;
					}
				}
			}
			if(!tf) ans++;
		}
		System.out.println(ans);
	}
}

class Edge{
	int vertex;
	long cost;
	public Edge(int v, long c){
		vertex = v;
		cost = c;
	}
}

class MinPath{
	int vertex;
	long cost;
	Edge edge;
	public MinPath(int v, long c, Edge e){
		vertex = v;
		cost = c;
		edge = e;
	}
}

class FastScanner {
    private InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    public FastScanner(InputStream in) {
		this.in = in;
	}
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
    private int readByte() {
    	if (hasNextByte()) return buffer[ptr++];
    	else return -1;
    }
    private static boolean isPrintableChar(int c){
    	return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
    	while(hasNextByte() && !isPrintableChar(buffer[ptr]))
    		ptr++; return hasNextByte();
    }
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
    public double nextDouble() {
    	return Double.parseDouble(next());
    }
}