import java.io.*;
import java.util.*;

public class Main {
	
	static int MOD = 1000000007;
	static int N;
	static ArrayList<ArrayList<Integer>> G;
	static boolean[][] visited;
	static int[][] dp;
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		N = sc.nextInt();
		G = new ArrayList<ArrayList<Integer>>();
		for(int i = 0; i < N; i++) G.add(new ArrayList<Integer>());
		for(int i = 0; i < N-1; i++){
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			G.get(a).add(b);
			G.get(b).add(a);
		}
		
		visited = new boolean[N][2];
		dp = new int[N][2];
		
		int ans = (solve(-1, 0, 0) + solve(-1, 0, 1)) % MOD;
		System.out.println(ans);
		
	}//end main
	
	public static int solve(int from, int v, int wb){
		if(visited[v][wb]) return dp[v][wb];
		
		long res = 1;
		if(wb == 1){
			for(int to : G.get(v)){
				if(to == from) continue;
				res *= solve(v, to, 0);
				res %= MOD;
			}
		}else{
			for(int to : G.get(v)){
				if(to == from) continue;
				int sum = solve(v, to, 0) + solve(v, to, 1);
				sum %= MOD;
				res *= sum;
				res %= MOD;
			}
		}
		
		visited[v][wb] = true;
		dp[v][wb] = (int)res;
		return dp[v][wb];
	}
	
}//end Main

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