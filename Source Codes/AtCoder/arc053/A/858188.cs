using System;
using System.Linq;

public class Test
{
	public static void Main()
	{
		var a = scan();
		int h = a[0];
		int w = a[1];
		var ans = 0;
		ans += (h-1)*w;
		ans += h*(w-1);
		Console.WriteLine(ans);
		
	}
	static int[] scan()
	{
		return Console.ReadLine().Split().Select(int.Parse).ToArray();
	}
}