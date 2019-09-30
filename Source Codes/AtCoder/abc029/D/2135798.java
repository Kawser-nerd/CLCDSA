import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	static int[][][] memo = new int[11][2][11];
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner(System.in);
		String n = sc.next();
		for(int i=0; i<11; i++) {
			for(int j=0; j<2; j++) {
				Arrays.fill(memo[i][j], -1);	
			}
		}
		System.out.println(dp(n, 0, 1, 0));
	}
	
	static int dp(String n, int k, int f, int acc) {
		if(n.length()==k) {
			return acc;
		}
		if(memo[k][f][acc]!=-1) {
			return memo[k][f][acc];
		}
		if(f==0) {
			int sum = 0;
			for(int i=0; i<=9; i++) {
				if(i==1) {
					sum += dp(n, k+1, 0, acc+1);
				} else {
					sum += dp(n, k+1, 0, acc);
				}
			}
			return memo[k][0][acc] = sum;
		} else {
			int sum = 0;
			for(int i=0; i<=9; i++) {
				if(i < Character.getNumericValue(n.charAt(k))) {
					if(i==1) {
						sum += dp(n, k+1, 0, acc+1);
					} else {
						sum += dp(n, k+1, 0, acc);
					}
				} else if(i== Character.getNumericValue(n.charAt(k))) {
					if(i==1) {
						sum += dp(n, k+1, 1, acc+1);
					} else {
						sum += dp(n, k+1, 1, acc);
					}
				}
			}
			return memo[k][1][acc] = sum;
		}
	}
	static class MyScanner
	{
		BufferedReader br;
		StringTokenizer st;
		public MyScanner(InputStream s)
		{
			br=new BufferedReader(new InputStreamReader(s));
		}
		public String nextLine() throws IOException
		{
			return br.readLine();
		}
		public String next() throws IOException
		{
			while(st==null || !st.hasMoreTokens())
				st=new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int nextInt() throws IOException
		{
			return Integer.parseInt(next());
			
		}
		public double nextDouble() throws IOException
		{
			return Double.parseDouble(next());
		}
		public boolean ready() throws IOException
		{
			return br.ready();
		}
		public long nextLong() throws IOException
		{
			return Long.parseLong(next());
		}
	}
}