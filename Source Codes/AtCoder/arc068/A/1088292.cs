using System;

public class Test
{
	public static void Main()
	{
		long n = long.Parse(Console.ReadLine());
		long ans = (n / 11) * 2;
		if (n % 11 > 6)
		{
			ans += 2;
		}
		else if (n % 11 != 0)
		{
			ans++;
		}
		Console.WriteLine(ans);
	}
}