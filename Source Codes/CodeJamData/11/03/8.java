/*

Author: Yiu Yu Ho
Creation: <Creation Date>
Last Updated: <Last Updated Date>
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class C
{
    public PrintStream out = System.out;
    public PrintStream err = System.err;
    public Scanner in = new Scanner(System.in);
    public DecimalFormat fmt = new DecimalFormat("0.000000000");
    
	//               123456789
	public int T9 = 1000000000;    
    
    public void main()
    {
        try
        {
//          err = new PrintStream(new FileOutputStream("error.log"), true);			
            int TCase,cc;
            int n, sum, min;
            int[] v;

            TCase = in.nextInt();
            for(cc = 1; cc <= TCase; ++cc)
            {
            	n = iInt();
            	v = new int[n];
            	for(int i = 0; i < n; ++i) v[i] = iInt();
            	
            	sum = 0;
            	min = T9;
            	for(int i = 0; i < n; ++i)
            	{
            		sum += v[i];
            		min = Math.min(min, v[i]);
            	}
            	
            	if(even(v))
            	{
                    out.println("Case #" + cc + ": " + (sum - min));
            	}
            	else
            	{
                    out.println("Case #" + cc + ": NO");
            	}
            }//end for cc = 1 ... TCase
        }
        catch(Exception e) { e.printStackTrace(); }
    }//end public void main()

    public boolean even(int[] v)
    {
    	int cnt;
    	for(int i = 0; i < 25; ++i)
    	{
    		cnt = 0;
    		for(int x = 0; x < v.length; ++x) if(in(i, v[x])) ++cnt;
    		
    		if(cnt % 2 != 0) return false;
    	}
    	
    	return true;
    }
    
    public boolean in(int x, int set) { return ((1<<x) & set) != 0; }
    
    public static void main(String[] args)
    {
        long startTime = System.currentTimeMillis();
        (new C()).main();
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
