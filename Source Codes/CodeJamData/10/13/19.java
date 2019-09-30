
import java.io.*;
import java.util.*;
import java.text.*;

public class CS
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");
	
	public int Amin, Amax, Bmin, Bmax;
	
	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"), true);			
			int TCase,cc;			
			
			int i, j, k;
			/*
			int[][] T = new int[20][20];
			for(i=0;i<20;++i) for(j=0;j<20;++j)
			{
				if(i==0) T[i][j] = 1;
				if(j==0) T[i][j] = 1;
				
			}
			*/
			
			int A, B;
			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				Amin = in.nextInt();
				Amax = in.nextInt();
				Bmin = in.nextInt();
				Bmax = in.nextInt();
				
				int res = 0;
				for(A=Amin;A<=Amax;++A) for(B=Bmin;B<=Bmax;++B)
				{
					res += sim(A, B);
				}
				
				out.println("Case #"+cc+": "+res);
			}//end for cc = 1 ... TCase
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	public int sim(int A, int B)
	{
		if(A == B) return 0;
		if(A < B) return sim(B, A);
		if(A >= 2*B) return 1;
		
		return 1 - sim(B, A-B);
	}

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new CS()).main();
		long endTime = System.currentTimeMillis();
		
		long ms = endTime - startTime;
		long sec = ms/1000; ms = ms%1000;
		long min = sec/60; sec = sec%60;

		System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
	}
}
