import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
	
	public static final long MOD = 1000000007;
	
	public static long memoized(int deep, int n, long[] memo){
		//System.out.println(deep);
		
		if(deep >= n){
			return 1;
		}else if(memo[deep] >= 0){
			return memo[deep];
		}else{
			long ret = 0;
			
			for(int i = n - deep + 1; i >= 1; i--){
				final int next_deep = deep + i;
				
				ret += memoized(next_deep, n, memo);
				ret %= MOD;
				
				if(next_deep <= n && i >= 2){
					ret += n - 1;
					ret %= MOD;
				}
			}
			
			return memo[deep] = ret;
		}
	}
	
	public static void main(String[] args) throws IOException {
		try(Scanner sc = new Scanner(System.in)){
			
			final int n = sc.nextInt();
			final long n_value = n;
			
			long[] memo = new long[n + 1];
			memo[0] = (n) % MOD;
			memo[1] = ((long)(n) * (long)(n)) % MOD;
			
			long sum = 0;
			for(int i = 2; i <= n; i++){
				memo[i] += memo[i - 1];
				memo[i] %= MOD;
				
				memo[i] += sum + (n_value - (i - 1));
				memo[i] %= MOD;
				
				memo[i] += (n_value - 1) * (n_value - 1);
				memo[i] %= MOD;
				
				sum += memo[i - 2];
				sum %= MOD;
				
				//System.out.println(memo[i]);
			}
			
			//System.out.println(Arrays.toString(memo));
			
			System.out.println(memo[n - 1]);
			//System.out.println(memoized(0, n, memo));
		}
	}
	
	public static class Scanner implements Closeable {
		private BufferedReader br;
		private StringTokenizer tok;
 
		public Scanner(InputStream is) throws IOException {
			br = new BufferedReader(new InputStreamReader(is));
		}
 
		private void getLine() throws IOException {
			while (!hasNext()) {
				tok = new StringTokenizer(br.readLine());
			}
		}
 
		private boolean hasNext() {
			return tok != null && tok.hasMoreTokens();
		}
 
		public String next() throws IOException {
			getLine();
			return tok.nextToken();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
		
		public int[] nextIntArray(int n) throws IOException {
			final int[] ret = new int[n];
			for(int i = 0; i < n; i++){
				ret[i] = this.nextInt();
			}
			return ret;
		}
		
		public long[] nextLongArray(int n) throws IOException {
			final long[] ret = new long[n];
			for(int i = 0; i < n; i++){
				ret[i] = this.nextLong();
			}
			return ret;
		}
 
		public void close() throws IOException {
			br.close();
		}
	}
}