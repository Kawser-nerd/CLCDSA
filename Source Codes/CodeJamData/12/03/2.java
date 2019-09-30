//input file must be in.txt in this directory
//output file will be out.txt

import java.io.*;
import java.util.*;
public class C
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
		int a,b;
		a = in.nextInt();
		b = in.nextInt();
		int i = a;
		int firstDigit = 1;
		int numDigits = 0;
		while (i > 0)
		{
			i /= 10;
			firstDigit *= 10;
			numDigits++;
		}
		int [] alreadyDone = new int[numDigits];
		firstDigit /= 10;
		int cur,m;
		int tot = 0;
		boolean notDone;
		for (i = a; i < b; i++)
		{
			cur = i;
			for (int j = 1; j < numDigits; j++)
				alreadyDone[j] = -1;
			for (int j = 1; j < numDigits; j++)
			{
				m = cur % 10;
				cur = (cur / 10) + (m * firstDigit);
				if (cur > i && cur <= b)
				{
					notDone = true;
					for (int k = 1; k < j; k++)
					{
						if (alreadyDone[k] == cur)
						{
							notDone = false;
							break;
						}
					}
					if (notDone)
					{
						alreadyDone[j] = cur;
						tot++;
					}
				}
			}
		}
		out.print(tot);
	}
}
