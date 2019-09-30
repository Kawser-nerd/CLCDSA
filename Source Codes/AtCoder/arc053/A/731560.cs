using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class Program
{
	static void Main(string[] args)
	{
		new Program().Solve();
	}

	void Solve()
	{
		string[] ss = Console.ReadLine().Split();
		BigInteger h = BigInteger.Parse(ss[0]);
		BigInteger w = BigInteger.Parse(ss[1]);
		Console.WriteLine(h * (w - 1) + (h - 1) * w);
	}
}