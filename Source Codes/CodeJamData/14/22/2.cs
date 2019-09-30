using System;

public class B
{
	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		for(int testcase = 1; testcase <= tests; testcase++)
		{
			Console.Write("Case #{0}: ", testcase);
			
			string[] parts = Console.ReadLine().Split();
			long a = long.Parse(parts[0]);
			long b = long.Parse(parts[1]);
			long k = long.Parse(parts[2]);

			long ans = 0;
			for(long i = 0; i < a; i++)
				for(long j = 0; j < b; j++)
					if((i & j) < k)
						ans++;
			
			Console.WriteLine(ans);
		}
	}
}