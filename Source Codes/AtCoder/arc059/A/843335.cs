using System;
class E
{
	static void Main()
	{
		int N = int.Parse(Console.ReadLine());
		var a = new int[N];
		var strs = Console.ReadLine().Split();
		for (var i = 0; i < N; i++) a[i] = int.Parse(strs[i]);
		var min = 100000000000000000L;
		for (var t = -100; t<=100;t++)
		{
			var sum = 0L;
			foreach (var x in a) sum += (x - t) * (x - t);
			min = Math.Min(min, sum);
		}
		Console.WriteLine(min);
	}
}