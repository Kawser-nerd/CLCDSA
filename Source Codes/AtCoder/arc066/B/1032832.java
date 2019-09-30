import java.io.*;
import java.util.*;
import java.util.function.IntPredicate;


public class Main {
	
	long N;
	int[] A;
	long div = 1000000007;
	long[][][][] dp;
	
	long dfs(int idx, int justAdd, int justXor, int carry){
		if(idx == 0){
			if(carry == 1) return 1;
			else if((justAdd == 1 || justXor == 1) && !get(N, 0)) return 1;
			else return 2;
		}
		if(dp[idx][justAdd][justXor][carry] != -1){
			return dp[idx][justAdd][justXor][carry];
		}
		long ans = 0;
		if(justAdd == 1 && justXor == 1){
			if(get(N, idx)){
				if(carry == 1){
					ans = mod(dfs(idx - 1, 0, 0, 0) + dfs(idx - 1, 1, 0, 1) + dfs(idx - 1, 0, 1, 1));
				}else{
					ans = mod(dfs(idx - 1, 0, 0, 0) + dfs(idx - 1, 1, 1, 0) + dfs(idx - 1, 1, 0, 1));
				}
			}else{
				ans = dfs(idx - 1, 1, 1, 0);
			}
		}else if(justAdd == 1 && justXor == 0){
			if(get(N, idx)){
				if(carry == 1){
					ans = mod(dfs(idx - 1, 0, 0, 0) + dfs(idx - 1, 0, 0, 1) + dfs(idx - 1, 1, 0, 1));
				}else{
					ans = mod(dfs(idx - 1, 0, 0, 0) + dfs(idx - 1, 1, 0, 0) + dfs(idx - 1, 1, 0, 1));
				}
			}else{
				if(carry == 1){
					ans = mod(dfs(idx - 1, 1, 0, 0) + dfs(idx - 1, 1, 0, 1));
				}else{
					ans = dfs(idx - 1, 1, 0, 0);
				}
			}
		}else if(justAdd == 0 && justXor == 1){
			if(get(N, idx)){
				if(carry == 1){
					ans = mod(dfs(idx - 1, 0, 0, 0) + dfs(idx - 1, 0, 0, 1) + dfs(idx - 1, 0, 1, 1));
				}else{
					ans = mod(dfs(idx - 1, 0, 0, 0) + dfs(idx - 1, 0, 0, 1) + dfs(idx - 1, 0, 1, 0));
				}
			}else{
				if(carry == 1){
					ans = mod(dfs(idx - 1, 0, 1, 0) + dfs(idx - 1, 0, 1, 1));
				}else{
					ans = mod(dfs(idx - 1, 0, 1, 0) + dfs(idx - 1, 0, 1, 1));
				}
			}
		}else{
			if(carry == 1){
				ans = mod(dfs(idx - 1, 0, 0, 0) + 2 * dfs(idx - 1, 0, 0, 1));
			}else{
				ans = mod(2 * dfs(idx - 1, 0, 0, 0) + dfs(idx - 1, 0, 0, 1));
			}
		}
		return dp[idx][justAdd][justXor][carry] = ans;
	}
	
	public void solve() {
		N = nextLong();
		//s2(N);
		dp = new long[100][2][2][2];
		for(int i = 0; i < dp.length; i++){
			for(int j = 0; j < dp[i].length; j++){
				for(int k = 0; k < dp[j].length; k++){
					for(int l = 0; l < dp[k].length; l++){
						dp[i][j][k][l] = -1;
					}
				}
			}
		}
		out.println(dfs(63, 1, 1, 0));
		
	}
	
	public void s2(long N){
		HashSet<Long> set = new HashSet<>();
		for(int i = 0; i <= N; i++){
			for(int j = 0; j <= N; j++){
				if(i + j <= N && (i ^ j) <= N){
					set.add((long)(i + j) << 32 | (i ^ j));
				}
			}
		}
		for(long v : set){
			System.err.println((v & 0xffffffffL) +  " " + (v >> 32));
		}
		System.err.println(set.size());
	}
	
	long mod(long val){
		return val % div;
	}
	
	public boolean get(long bit, long idx){
		return (bit & (1L << idx)) != 0;
	}
	
	public long pow(long n){
	    long sum = 1;
	    long x = 2;
	    while (n > 0) {
	        if ((n & 1) == 1) {
	            sum *= x;
	            sum %= div;
	        }
	        x *= x;
	        x %= div;
	        n >>= 1;
	    }
	    return sum;
	}

	private static PrintWriter out;

	public static void main(String[] args) {
		out = new PrintWriter(System.out);
		new Main().solve();
		out.flush();
	}

	public static int nextInt() {
		int num = 0;
		String str = next();
		boolean minus = false;
		int i = 0;
		if (str.charAt(0) == '-') {
			minus = true;
			i++;
		}
		int len = str.length();
		for (; i < len; i++) {
			char c = str.charAt(i);
			if (!('0' <= c && c <= '9'))
				throw new RuntimeException();
			num = num * 10 + (c - '0');
		}
		return minus ? -num : num;
	}

	public static long nextLong() {
		long num = 0;
		String str = next();
		boolean minus = false;
		int i = 0;
		if (str.charAt(0) == '-') {
			minus = true;
			i++;
		}
		int len = str.length();
		for (; i < len; i++) {
			char c = str.charAt(i);
			if (!('0' <= c && c <= '9'))
				throw new RuntimeException();
			num = num * 10l + (c - '0');
		}
		return minus ? -num : num;
	}

	public static String next() {
		int c;
		while (!isAlNum(c = read())) {
		}
		StringBuilder build = new StringBuilder();
		build.append((char) c);
		while (isAlNum(c = read())) {
			build.append((char) c);
		}
		return build.toString();
	}

	private static byte[] inputBuffer = new byte[1024];
	private static int bufferLength = 0;
	private static int bufferIndex = 0;

	private static int read() {
		if (bufferLength < 0)
			throw new RuntimeException();
		if (bufferIndex >= bufferLength) {
			try {
				bufferLength = System.in.read(inputBuffer);
				bufferIndex = 0;
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufferLength <= 0)
				return (bufferLength = -1);
		}
		return inputBuffer[bufferIndex++];
	}

	private static boolean isAlNum(int c) {
		return '!' <= c && c <= '~';
	}
}