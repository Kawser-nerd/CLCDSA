
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.text.*;

public class B 
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");
	
	public int n;
	public BigInteger[] t;
	public BigInteger T;
	
	public BigInteger zero = BigInteger.ZERO;
	public BigInteger one = BigInteger.ONE;
	public BigInteger two = one.add(one);	
	
	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"), true);			
			int TCase,cc;
			int i, j;

			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				n = in.nextInt();
				
				t = new BigInteger[n];
				for(i=0;i<n;++i) t[i] = new BigInteger(in.next());
				
				T = null;
				for(i=0;i<n;++i) for(j=0;j<n;++j) if(t[i].compareTo(t[j]) > 0)
				{
					if(T == null) T = t[i].subtract(t[j]);
					else T = T.gcd(t[i].subtract(t[j]));
				}
				
				BigInteger A = t[0].add(T).subtract(one);
				BigInteger k = A.divide(T);
				
				out.println("Case #" + cc + ": " + (k.multiply(T).subtract(t[0])));
			}//end for cc = 1 ... TCase
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	public int iInt() { return in.nextInt(); }
	public long iLong() { return in.nextLong(); }
	public String iToken() { return in.next(); }
	public String iLine() { return in.nextLine(); }

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new B()).main();
		long endTime = System.currentTimeMillis();
		
		long ms = endTime - startTime;
		long sec = ms/1000; ms = ms%1000;
		long min = sec/60; sec = sec%60;

		System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
	}
}
