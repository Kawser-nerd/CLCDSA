import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	int []a=new int [n];
	for(int i=0;i<n;i++)
		a[i]=sc.nextInt();
	
	int start=0;
	int end=0;
	int v=0;
	long s=0;
	long ans=0;
	boolean f=true;
	while(end<n)
	{
		if(f)
		{	
			s+=a[end];
			v^=a[end];
		}
		//System.out.println(start+" "+end+" "+s+" "+v);
		if(s==v)
		{	
			f=true;
			end++;
		}	
		else
		{
			f=false;
			long len=end-start;
			ans+=len;
			s-=a[start];
			v^=a[start];
			start++;
			
		}
		
		
				
	}

	if(f)
	{
		long len=(end-start);
		ans+=(len)*(len-1)/2;
		ans+=len;
	}
	
	System.out.println(ans);	
		
	

	}
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;
		public Scanner(InputStream s)
		{
			br=new BufferedReader(new InputStreamReader(s));
		}
		public Scanner(String s) throws FileNotFoundException
		{
			br=new BufferedReader(new FileReader(s));
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