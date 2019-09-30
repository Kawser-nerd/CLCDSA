//input file must be "in.txt"
//output file is "out.txt"
import java.util.Scanner;
import java.io.*;
import java.math.BigInteger;

public class A
{
	public static void main(String[] args)throws Throwable
	{
		Scanner in = new Scanner(new File("in.txt"));
		PrintStream out = new PrintStream(new File("out.txt"));
		
		int t = in.nextInt();
		in.nextLine();
		
		for (int c = 1; c <= t; c++)
		{
			out.print("Case #");
			out.print(c);
			out.print(": ");
			out.println(getSolution(in));
		}
		
	}
	private static String getSolution(Scanner in)
	{
		long n;
		int pd, pg;
		n = in.nextLong();
		pd = in.nextInt();
		pg = in.nextInt();
		
		int factor = gcf(100,pd);
		
		if (100/factor > n)
			return "Broken";
		
		if ((pg == 100 && pd != 100) || (pg == 0 && pd != 0))
			return "Broken";
		
		return "Possible";
	}
	
	public static int gcf(int a, int b) 
	{
		int s;
		if (a > b)
			s = b;
		else
			s = a;
		for (int i = s; i > 0; i--) 
		{
			if ((a%i == 0) && (b%i == 0))
				return i;
		}
		return -1;
	}
}
