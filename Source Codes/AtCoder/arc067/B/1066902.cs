using System;
using System.Linq;

public class Program
{
	public static void Main()
	{
		int[] NAB = Console.ReadLine().Split().Select(int.Parse).ToArray();
		int N = NAB[0], A = NAB[1], B = NAB[2];
		int[] X = Console.ReadLine().Split().Select(int.Parse).ToArray();
		long ans = 0;
		for (int i = 1; i < N; i++)
		{
			ans += Math.Min((long)(X[i] - X[i - 1]) * A, B);
		}
		Console.WriteLine(ans);
	}
}