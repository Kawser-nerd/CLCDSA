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
		var RB = Console.ReadLine().Split(' ');
		var R = BigInteger.Parse(RB[0]);
		var B = BigInteger.Parse(RB[1]);
		var xy = Console.ReadLine().Split(' ');
		var x = BigInteger.Parse(xy[0]);
		var y = BigInteger.Parse(xy[1]);

		var max_r = R / x;
		var max_b = B / y;
		if (max_r == 0 && max_b == 0)
			Console.WriteLine(0);
		else if (max_r == 0)
			Solve(B, R, y, x);
		else
			Solve(R, B, x, y);

		Console.Out.Flush();
		return;
	}

	static void Solve(BigInteger R, BigInteger B, BigInteger x, BigInteger y)
	{
		var max_r = R / x;
		if (max_r > B) max_r = B;
		var index = max_r / 2;
		if (index == 0)
		{
			var n1 = GetN(R, B, x, y, index);
			var n2 = GetN(R, B, x, y, index + 1);
			if (n1 > n2)
				Console.WriteLine(n1);
			else
				Console.WriteLine(n2);
			return;
		}

		BigInteger min = 0;
		BigInteger max = max_r;

		while (true)
		{
			var n = GetN(R, B, x, y, index);

			if (index >= max_r)
			{
				Console.WriteLine(n);
				return;
			}
			if (index <= 0)
			{
				Console.WriteLine(n);
				return;
			}

			var next = GetN(R, B, x, y, index + 1);
			var prev = GetN(R, B, x, y, index - 1);

			if (n > next && n >= prev)
			{
				Console.WriteLine(n);
				return;
			}

			else if (n <= next && n >= prev) //?
			{
				var add = (max - index) / 2;
				if (add == 0) add = 1;
				min = index;
				index = index + add;
			}
			else //?
			{
				var sub = (index - min) / 2;
				if (sub == 0) sub = 1;
				max = index;
				index = index - sub;
			}
		}
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