import java.util.*;
import java.io.*;
public class B
{
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("B-large.out")));
		
		int t = in.nextInt();
		
		for(int y = 0; y < t; y++)
		{
			double c = in.nextDouble();
			double f = in.nextDouble();
			double x = in.nextDouble();
			
			long low = 0;
			long high = (long)1E6;
			while(low + 2 < high)
			{
				long mid1 = low + (high - low) / 3;
				long mid2 = low + 2 * (high - low) / 3;
				
				if(getTime(mid1, c, f, x) < getTime(mid2, c, f, x))
				{
					high = mid2 - 1;
				}
				else
				{
					low = mid1;
				}
			}
			
			double result = Double.POSITIVE_INFINITY;
			for(long z = low; z <= high; z++)
			{
				result = Math.min(result, getTime(z, c, f, x));
			}
			
			out.printf("Case #%d: %.7f\n", y + 1, result);
		}
		
		out.close();
	}
	
	public static double getTime(long buildings, double c, double f, double x)
	{
		double time = 0;
		double rate = 2;
		for(int i = 0; i < buildings; i++)
		{
			time += c / rate;
			rate += f;
		}
		
		return time + (x / rate);
	}
}
