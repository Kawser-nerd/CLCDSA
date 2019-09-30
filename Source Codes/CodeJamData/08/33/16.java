import java.io.*;
import java.util.*;

public class Main {

	Scanner in;
	PrintWriter out;
	
	String IFILE = "c-small-attempt0.in";
	String OFILE = "c-small-attempt0.out";
	
	final long MOD = 1000000007;
	
	public void run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter(OFILE);
		
		int nt = in.nextInt();
		for (int it=0; it <nt; it++)
		{
			int n = in.nextInt();
			int m = in.nextInt();
			long x = in.nextInt();
			long y = in.nextInt();
			long z = in.nextInt();
			
			long[] a = new long[m];
			for (int i=0; i<m; i++) a[i] = in.nextLong();
			
			long[] mas = new long[n];
			for (int i=0; i<n; i++)
			{
				mas[i] = a[i%m];
				a[i%m] = (x*a[i%m] + y*(i+1)) % z;
			}
			
			long[] f = new long[n];
			Arrays.fill(f, 1);
			for (int i=0; i<n; i++)
				for (int j=0; j<i; j++)
					if (mas[j]<mas[i]) f[i] = (f[i]+f[j])%MOD;
			
			long ans=0;
			for (int i=0; i<n; i++)
				ans = (ans+f[i])%MOD;
			
			out.println("Case #"+(it+1)+": "+ans);
		}
		
		out.close();
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

}
