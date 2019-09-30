import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner(System.in);
		final int N = sc.nextInt();
		final long[] a = new long[N];
		final long[] b = new long[N];
		for(int i=0; i<N; i++) {
			a[i] = sc.nextLong();
			b[i] = sc.nextLong();
		}
		int n = 0; // a < b
		int m = 0; // a > b
		int k = 0; // a == b
		for(int i=0; i<N; i++) {
			if(a[i]<b[i]) {
				n++;
			} else if(a[i]>b[i]){
				m++;
			} else {
				k++;
			}
		}
		if(m==0) {
			System.out.println(0);
		} else {
			long ans = 0;
			long minb = Long.MAX_VALUE;
			for(int i=0; i<N; i++) {
				if(a[i]>b[i]) {
					minb = Math.min(minb, b[i]);
				}
				ans += a[i];
			}
			System.out.println(ans-minb);
		}

	}
	
	static class Pair {
		long fst;
		long snd;
		Pair(long a, long b) {
			this.fst = a; this.snd = b;
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