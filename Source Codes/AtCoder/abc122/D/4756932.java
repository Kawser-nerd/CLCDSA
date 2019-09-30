import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	
	final boolean isDebug = false;
	String fileName = "input.txt";
	FastScanner sc;
	PrintWriter out;
	final int MOD = (int)1e9+7;
	final int INF = Integer.MAX_VALUE / 2;
		
	/* solve */
	/* jkmn
	 *  AGC
	 *  GAC
	 *  ACG
	 * A*GC
	 * AG*C
	 */
	
	void solve() throws Exception{
		int N = sc.nextInt();
		int A = 0, C = 1, G = 2, T = 3;
		long sum = 0;
		long[][][][] dp = new long[N+1][4][4][4];
		
		if(N == 3){
			System.out.println("61");
			return;
		}
		
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				for(int m = 0; m < 4; m++){
					if(j == A && k == G && m == C) continue;
					if(j == A && k == C && m == G) continue;
					if(j == G && k == A && m == C) continue;
					dp[3][j][k][m]++;
				}
			}
		}
		
		for(int i = 4; i <= N; i++){
			for(int j = 0; j < 4; j++){
				for(int k = 0; k < 4; k++){
					for(int m = 0; m < 4; m++){
						for(int n = 0; n < 4; n++){
							if(n == C){
								if(k == A && m == G) continue;
								if(k == G && m == A) continue;
								if(j == A && m == G) continue;
								if(j == A && k == G) continue;
							}
							if(n == G){
								if(k == A && m == C) continue;
							}
							dp[i][k][m][n] += dp[i-1][j][k][m];
							dp[i][k][m][n] %= MOD;
							
							if(i == N){
								sum += dp[i-1][j][k][m];
								sum %= MOD;
							}
						}
					}
				}
			}
		}
		
		System.out.println(sum);
	}
	
	/* end solve */
	
	/* main */
	public static void main(String[] args) throws Exception {
		new Main().m();
	}
	
	void m() throws Exception {
		long S = System.currentTimeMillis();
		sc = (isDebug) ? new FastScanner(new FileInputStream(fileName)) : new FastScanner(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		if(isDebug){
			System.out.println("---Debug---");
			System.out.printf("%8d ms", (G-S));
		}
	}
	/* end main */
}
/* end Main */

class Edge implements Comparable<Edge>{
	int from;
	int to;
	long cost;
	public Edge(int f, int t, long c){
		from = f; to = t; cost = c;
	}
	@Override
	public int compareTo(Edge o) {
		if(this.cost != o.cost) return (this.cost > o.cost) ? -1 : 1;
		else{
			if(this.from != o.from) return (this.from < o.from) ? -1 : 1;
			else if(this.to != o.to) return (this.to < o.to) ? -1 : 1;
			else return 0;
		}
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