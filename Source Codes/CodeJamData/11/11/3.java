/*
Author: Yiu Yu Ho
Creation: <Creation Date>
Last Updated: <Last Updated Date>
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class A
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");

	public int p, q, n;
	
	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"), true);
			
			int TCase = in.nextInt();
			for(int cc = 1; cc <= TCase; ++cc)
			{
				n = in.nextInt();
				p = in.nextInt();
				q = in.nextInt();
				
				out.println("Case #" + cc + ": " + (poss() ? "Possible" : "Broken"));
			}//end for cc = 1 ... TCase
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()

	public boolean poss()
	{
		for(int D = 1; D <= n; ++D)
		{
			if((p*D) % 100 != 0) continue;
			
			int W = p*D / 100;
			int c = 100 * W - q*D;
			
			for(int DD = 0; DD <= 1000000; ++DD)
			{
				if((q*DD - c) % 100 != 0) continue;
				int WW = (q*DD - c) / 100;
				
				if(0 <= WW && WW <= DD) return true;
			}
		}
		
		return false;
	}
	
	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new A()).main();
		long endTime = System.currentTimeMillis();

		long ms = endTime - startTime;
		long sec = ms/1000; ms = ms%1000;
		long min = sec/60; sec = sec%60;

		System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
	}

	public int    iInt()   { return in.nextInt(); }
	public long   iLong()  { return in.nextLong(); }
	public String iToken() { return in.next(); }
	public String iLine()  { return in.nextLine(); }
}//ends public class ???
