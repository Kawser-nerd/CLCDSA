import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner(System.in);
		final int n = sc.nextInt();
		final long c = sc.nextLong();
		long [] x = new long[n];
		long [] v = new long[n];
		for(int i=0; i<n; i++) {
			x[i] = sc.nextLong();
			v[i] = sc.nextLong();
		}
		// sub
		long [] imosv = new long[n];
		imosv[0] = v[0];
		for(int i=1; i<n; i++) {
			imosv[i] = imosv[i-1]+v[i];
		}
		long[] g = new long[n];
		g[0] = Math.max(0, v[0]-x[0]);
		for(int i=1; i<n; i++) {
			g[i] = Math.max(g[i-1], imosv[i]-x[i]);
		}
		long[] g2 = new long[n];
		g2[0] = Math.max(0, v[0]-2*x[0]);
		for(int i=1; i<n; i++) {
			g2[i] = Math.max(g2[i-1], imosv[i]-2*x[i]);
		}
		// main
		long ans = 0;
		// 1
		for(int m=1; m<n; m++) {
			ans = Math.max(ans, (imosv[n-1]-imosv[m-1])-(c-x[m])+g2[m-1]);
			ans = Math.max(ans, (imosv[n-1]-imosv[m-1])-2*(c-x[m])+g[m-1]);
		}
		// 2
		for(int m=0; m<n; m++) {
			ans = Math.max(ans, imosv[m]-x[m]);
		}
		// 3
		for(int k=0; k<n; k++) {
			if(k!=0) {
				ans = Math.max(ans, imosv[n-1]-imosv[k-1]-(c-x[k]));	
			} else {
				ans = Math.max(ans, imosv[n-1]-(c-x[k]));	
			}
			
		}
		System.out.println(ans);
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