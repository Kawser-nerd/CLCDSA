//input file must be in.txt in this directory
//output file will be out.txt

import java.io.*;
import java.util.*;
public class B
{
	public static Scanner in;
	public static PrintStream out;
	public static void main(String [] args) throws Throwable
	{
		in = new Scanner(new File("in.txt"));
		int cases = in.nextInt();
		in.nextLine();
		out = new PrintStream(new File("out.txt"));
		for (int i = 1; i <= cases; i++)
		{
			out.print("Case #" + i + ": ");
			printResult();
			out.println();
		}
	}
	public static void printResult()
	{
		int n,p,s;
		n = in.nextInt();
		s = in.nextInt();
		p = in.nextInt();
		
		int surprize;
		int good;
		if (p > 1)
		{
			surprize = (3*p)-4;
			good = (3*p) - 2;
		}
		else
		{
			surprize = p;
			good = p;
		}
		int tot = 0;
		int cur;
		for (int i = 0; i < n; i++)
		{
			cur = in.nextInt();
			if (cur >= good)
				tot++;
			else if(cur >= surprize && s > 0)
			{
				s--;
				tot++;
			}
		}
		out.print(tot);
	}
}
