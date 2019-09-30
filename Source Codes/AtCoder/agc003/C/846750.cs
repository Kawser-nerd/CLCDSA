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
		long n = Scan.Long();
		long[] ary = new long[n];
		for (long i = 0; i < n; i++)
		{
			long a = Scan.Long();
			ary[i] = a;
		}

		Dictionary<long, long> dic = new Dictionary<long, long>();
		var sorted_ary = (long[])ary.Clone();
		Array.Sort(sorted_ary);
		for (long i = 0; i < n; i++)
		{
			dic[sorted_ary[i]] = i;
		}

		for (long i = 0; i < n; i++)
		{
			ary[i] = dic[ary[i]];
		}

		int sum = 0;
		for (long i = 0; i < n; i++)
		{
			if (i % 2 != ary[i] % 2)
			{
				sum++;
			}
		}

		Console.WriteLine((int)Math.Ceiling(sum / 2.0));
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
	public static long Long()
	{
		return long.Parse(Read());
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