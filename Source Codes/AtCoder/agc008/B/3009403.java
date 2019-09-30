import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main{

	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		long[] a = new long[n+1];
		long[] b = new long[n+1];
		for(int i=1; i<=n; i++) a[i] = sc.nextLong();
		for(int i=1; i<=n; i++) {
			b[i]=b[i-1]+Math.max(a[i], 0);
			a[i]=a[i-1]+a[i];
		}
		long ans=0;
		for(int i=1; i+k-1<=n; i++) {
			ans=Math.max(ans, Math.max(a[i+k-1]-a[i-1],0)+b[i-1]+b[n]-b[i+k-1]);
		}
		System.out.println(ans);
		
 	}
	
	static void printArray(int[] a) {
		int n=a.length;
		for(int i=0; i<n; i++) {
			if(i==0) System.out.print(a[i]);
			else System.out.print(" "+a[i]);
		}
		System.out.println();
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