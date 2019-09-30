import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt();
		int []a=new int [n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		boolean ok=a[0]==0;
		for(int i=1;i<n;i++)
			if(a[i]-a[i-1]>1)
				ok=false;
		if(!ok)
		{
			System.out.println(-1);
			return;
		}
		long ans=0;
		for(int i=1;i<n;i++)
			if(a[i]>a[i-1])
				ans++;
			else
				ans+=a[i];
		pw.println(ans);
		
	
		
		
		
		pw.close();

	}
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;
		public Scanner(InputStream s)
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