/*

Author: Yiu Yu Ho
Creation: <Creation Date>
Last Updated: <Last Updated Date>
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;

public class D
{
    public PrintStream out = System.out;
    public PrintStream err = System.err;
    public Scanner in = new Scanner(System.in);
    public DecimalFormat fmt = new DecimalFormat("0.000000000");
    
    public int N = 1013;
    public BigDecimal[] D, fac;
    
    public BigDecimal[] E;
    
    public BigDecimal[][] exact;
    public MathContext context;
    
    public BigDecimal zero = BigDecimal.ZERO;
    public BigDecimal one = BigDecimal.ONE;
    
    public void main()
    {
        try
        {
//          err = new PrintStream(new FileOutputStream("error.log"), true);			
            int TCase,cc;
            
            //preCompute();

            TCase = in.nextInt();
            for(cc = 1; cc <= TCase; ++cc)
            {
            	int n = iInt();
            	int[] v = new int[n];
            	
            	int fix = 0;
            	for(int i = 0; i < n; ++i) 
            	{
            		v[i] = iInt();
            		if(v[i] == (i+1)) ++fix;
            	}
            	
                out.println("Case #" + cc + ": " + (n - fix));
            }//end for cc = 1 ... TCase
        }
        catch(Exception e) { e.printStackTrace(); }
    }//end public void main()

    public void preCompute()
    {
    	context = new MathContext(100);
    	
    	D = new BigDecimal[N];
    	D[0] = one; 
    	D[1] = zero;
    	
    	for(int i = 2; i < N; ++i) 
    	{
    		BigDecimal A = D[i-1].add(D[i-2], context);
    		BigDecimal B = new BigDecimal(i - 1);
    		
    		D[i] = A.multiply(B, context);
    	}
    	
    	fac = new BigDecimal[N];
    	fac[0] = one;
    	fac[1] = one;
    	
    	for(int i = 2; i < N; ++i) 
    	{
    		fac[i] = fac[i-1].multiply(new BigDecimal(i), context);
    	}
    	
    	err.println("Done computing D and fac.");
    	
    	exact = new BigDecimal[N][N];
    	
    	E = new BigDecimal[N];
    	E[0] = zero;
    	E[1] = zero;
    	for(int n = 2; n < N; ++n)
    	{
    		BigDecimal A, B, C;
    		
    		A = one.subtract(exact(0, n), context);
    		
    		B = one;
    		for(int i = 1; i <= n; ++i)
    		{
    			C = E[n - i].multiply(exact(i, n), context);
    			B = B.add(C, context);
    		}
    		
    		E[n] = B.divide(A, context);
    	}
    }
    
    public BigDecimal exact(int i, int n)
    {
    	if(exact[i][n] != null) return exact[i][n];
    	
    	BigDecimal A = fac[i].multiply(fac[n - i], context);
    	return exact[i][n] = D[n - i].divide(A, context);
    }
    
    public static void main(String[] args)
    {
        long startTime = System.currentTimeMillis();
        (new D()).main();
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
