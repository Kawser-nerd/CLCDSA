import java.util.*;

public class C
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int test = 1; test <= t; ++test)
		{
			int c = in.nextInt();
			int d = in.nextInt();
			long v = in.nextInt();
			long[] denom = new long[d];
			for (int i = 0; i < d; ++i)
				denom[i] = in.nextInt();
			
			System.out.printf("Case #%d: %d\n", test, solve(c, denom, v));
		}
	}
	
	public static long solve(int c, long[] denom, long v)
	{
		Arrays.sort(denom);
		long currentV = 0;
		int nextDenom = 0;
		int neededExtra = 0;
		
		while (currentV < v)
		{
			if (nextDenom != denom.length && denom[nextDenom] <= currentV+1)
			{
				currentV += denom[nextDenom] * c;
				++nextDenom;
			}
			else
			{
				++neededExtra;
				currentV += c * (currentV + 1);
			}
		}
		
		return neededExtra;
	}
}