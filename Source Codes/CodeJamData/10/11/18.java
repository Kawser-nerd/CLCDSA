

import java.io.*;
import java.util.*;
import java.text.*;

public class A
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");
	
	public char[][] B;
	public int n, K;
	
	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"), true);			
			int TCase,cc;
			

			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				n = in.nextInt();
				K = in.nextInt();
				
				B = new char[n][];
				for(int i=0;i<n;++i) B[i] = shift(in.next()).toCharArray();
				
				for(int i=0;i<n;++i)
				{
					//out.println(new String(B[i]));
				}
				
				boolean red, blue;
				red = check('R');
				blue = check('B');
				
				String T;
				if(red && blue)
				{
					T = "Both";
				}
				else if (red)
				{
					T = "Red";
				}
				else if(blue)
				{
					T = "Blue";
				}
				else
				{
					T = "Neither";
				}
				
				out.println("Case #"+cc+": " + T);
			}//end for cc = 1 ... TCase
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()

	public boolean check(char ch)
	{
		int i, j;
		for(i=0;i<n;++i) for(j=0;j<n;++j)
		{
			if(i+K-1 < n && OK(i, j, 1, 0, ch)) return true;
			if(j+K-1 < n && OK(i, j, 0, 1, ch)) return true;
			if(i+K-1 < n && j+K-1<n && OK(i, j, 1, 1, ch)) return true;
			if(i+K-1 < n && j-(K-1) >= 0 && OK(i, j, 1, -1, ch)) return true;
		}
		
		return false;
	}
	
	public boolean OK(int i, int j, int dx, int dy, char ch)
	{
		for(int x=0;x<K;++x)
		{
			if(B[i][j] != ch) return false;
			i += dx; j += dy;
		}
		return true;
	}
	
	public String shift(String S)
	{
		String R = "";
		for(int i=0;i<S.length();++i) if(S.charAt(i) != '.') R += S.charAt(i);
		while(R.length() < S.length()) R = "." + R;
		return R;
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
}
