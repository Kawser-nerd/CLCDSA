
import java.io.*;
import java.util.*;
import java.text.*;

public class SnapperChain
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");
	
	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"), true);			
			int TCase,cc;
			

			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				long n, K, L;
				n = in.nextLong();
				K = in.nextLong();
				
				L = (1L << n);
				out.println("Case #"+cc+": " + ((K%(L) == (L)-1)?"ON":"OFF"));
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
		(new SnapperChain()).main();
		long endTime = System.currentTimeMillis();
		
		long ms = endTime - startTime;
		long sec = ms/1000; ms = ms%1000;
		long min = sec/60; sec = sec%60;

		System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
	}
}
