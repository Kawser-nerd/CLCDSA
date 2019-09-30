

import java.io.*;
import java.util.*;
import java.text.*;

public class B
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");
	
	public int D, I, M, n;
	public int[] a;
	public int[][] sol;
	
	public int oo = 987654321;	
	
	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"), true);			
			int TCase,cc;
			
			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				D = in.nextInt();
				I = in.nextInt();
				M = in.nextInt();
				n = in.nextInt();
				
				int i, x;
				a = new int[n];
				for(i=0;i<n;++i) a[i] = in.nextInt();
				
				sol = new int[n+1][300];
				init(sol, -1);
				
				int res = D * n;
				
				//i: first non-del value
				for(i=0;i<n;++i)
				{
					for(x=0;x<=255;++x)
					{
						res = Math.min(res, D*i + Math.abs(a[i] - x) + solve(i+1, x));
					}
				}
				
				out.println("Case #"+cc+": " + res);
			}//end for cc = 1 ... TCase
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()

	public int solve(int i, int last)
	{
		if(sol[i][last] >= 0) return sol[i][last];
		
		int ret;
		
		if(i >= n) ret = 0;
		else
		{
			ret = oo;
			
			//delete a[i]
			ret = Math.min(ret, D + solve(i+1, last));
			
			int x;
			for(x=0;x<=255;++x) ret = Math.min(ret, insert(last, x) + Math.abs(x - a[i]) + solve(i+1, x));
		}
		
		return sol[i][last] = ret;
	}
	
	public int insert(int x, int y)
	{
		int T = Math.abs(x-y);
		if(T <= M) return 0;
		if(M == 0) return oo;
		return I*((T+M-1)/M - 1);
	}
	
	public void init(int[][] A, int val) 
	{ 
		for(int i=0;i<A.length;++i) Arrays.fill(A[i], val); 
	}	
	
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
