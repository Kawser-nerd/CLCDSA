import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class C 
{
	public static int n;
	public static long low, high;
	public static BigInteger lowB, highB;
	public static long a [];
	public static long sol;

//	public static boolean check (BigInteger d)
//	{
//		for (int i = 0; i < n; i++)
//			if ((!d.mod(a [i]).equals(BigInteger.ZERO)) && (!a [i].mod(d).equals(BigInteger.ZERO)))
//				return false;
//		return true;
//	}
	
	public static boolean check (long d)
	{
		for (int i = 0; i < n; i++)
			if ((d % a [i] != 0) && (a [i] % d != 0))
				return false;
		if ((d >= low) && (d <= high))
			return true;
		else
			return false;
	}
	
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader input =  new BufferedReader (new FileReader (new File ("C-large.in")));
			BufferedWriter output = new BufferedWriter (new FileWriter (new File ("C-large.out")));
			int testNumber = Integer.parseInt(input.readLine());
			Scanner scanner = new Scanner (input);
			for (int t = 1; t <= testNumber; t++)
			{
				System.out.println(t + " " + testNumber);
				n = scanner.nextInt();
				low = scanner.nextLong();
				lowB = new BigInteger (Long.toString(low));
				high = scanner.nextLong();
				highB = new BigInteger (Long.toString(high));
				a = new long [n];
				for (int i = 0; i < n; i++)
					a [i] = scanner.nextLong();
				boolean found = false;
				
				BigInteger lcm = new BigInteger (Long.toString(a [0]));
				for (int i = 1; i < n; i++)
				{
					BigInteger gcd = lcm.gcd(new BigInteger (Long.toString(a [i])));
					lcm = lcm.multiply(new BigInteger (Long.toString(a [i]))).divide(gcd);
					if (lcm.compareTo(highB) > 0)
						break;
				}
				System.out.println(lcm);
				if (lcm.compareTo(highB) <= 0)
				{
					long sum = lcm.longValue();
					long tmp = lcm.longValue();
					while (sum <= high)
					{
						if (sum >= low)
						{
							sol = sum;
							found = true;
							break;
						}
						sum = sum + tmp;
					}
				}
					
				long max = a [0];
				for (int i = 1; i < n; i++)
					if (max < a [i])
						max = a [i];
				long d = 1;
//				if (Math.sqrt(max) <= low)
//					d = low;
				while (d * d <= max)
				{
					if (max % d == 0)
					{
						if (check (d) == true)
						{
							if ((!found) || ((found) && (sol > d)))
							{
								found = true;
								sol = d;
								break;
							}
						}
						long dd = max / d;
						if (check (dd) == true)
						{
							if ((!found) || ((found) && (sol > dd)))
							{
								found = true;
								sol = dd;
							}
						}
					}
					d++;
				}
				
				if (found)
					output.write("Case #" + t + ": " + sol);
				else
					output.write("Case #" + t + ": NO");
				output.newLine();
			}
			output.close();
			input.close();
		}
		catch (IOException ex)
		{
			ex.printStackTrace();
		}

	}

}
