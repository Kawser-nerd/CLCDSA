using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class Program
{
	static void Main(string[] args)
	{
		var R = Scan.BigInt();
		var B = Scan.BigInt();
		var x = Scan.BigInt();
		var y = Scan.BigInt();
		var max_r = R / x;
		var max_b = B / y;
		if (max_r == 0 && max_b == 0)
			Console.WriteLine(0);
		else if (max_r == 0)
			Solve(B, R, y, x);
		else
			Solve(R, B, x, y);
	}

	static void Solve(BigInteger R, BigInteger B, BigInteger x, BigInteger y)
	{
		var max_r = R / x;
		if (max_r > B) max_r = B;

		BigInteger min = 0;
		BigInteger max = max_r;
		while (max - min > 0)
		{
			var index = ((max - min) / 2) + min;
			var n = GetN(R, B, x, y, index);
			var next = GetN(R, B, x, y, index + 1);
			var prev = GetN(R, B, x, y, index - 1);
			if (n <= next && n >= prev) //?
				min = index + 1;
			else if (n >= next && n <= prev) //?
				max = index - 1;
			else
				max = min = index;
		}
		Console.WriteLine(GetN(R, B, x, y, max));
	}

	static BigInteger GetN(BigInteger R, BigInteger B, BigInteger x, BigInteger y, BigInteger index)
	{
		var r = index;
		var rest_r = R - r * x;
		var rest_b = B - r;
		var b = rest_b / y;
		if (b > rest_r) b = rest_r;
		return r + b;
	}
}



static class Scan
{
	static Queue<string> _queue = new Queue<string>();
	public static string Str()
	{
		return Read();
	}
	public static char Char()
	{
		return Read()[0];
	}
	public static int Int()
	{
		return int.Parse(Read());
	}
	public static BigInteger BigInt()
	{
		return BigInteger.Parse(Read());
	}
	public static double Double()
	{
		return double.Parse(Read());
	}
	static string Read()
	{
		if (_queue.Count > 0)
			return _queue.Dequeue();
		foreach (var s in Console.ReadLine().Split()) _queue.Enqueue(s);
		return _queue.Dequeue();
	}
}