//#pragma warning disable
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using System.Threading.Tasks;
using static System.Math;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => long.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var I = G();
		int A = I[0], B = I[1], C = I[2], D = I[3], E = I[4], F = I[5];
		var sugar = new bool[F + 1];
		sugar[0] = true;
		for (var i = C; i <= F; i++) sugar[i] = sugar[i - C] || (i >= D && sugar[i - D]);
		int mA = F / (100 * A), mB = F / (100 * B);
		int gW = 100 * A, gS = 0;
		for (var a = 0; a <= mA; a++)
			for (var b = 0; b <= mB; b++)
			{
				var w = a * A + b * B;
				var m = Min(F - 100 * w, E * w);
				if (m <= 0) continue;
				var s = m;
				while (!sugar[s]) s--;
				if (s * gW > gS * w * 100)
				{
					gW = w * 100;
					gS = s;
				}
			}
		WriteLine("{0} {1}", gW + gS, gS);
	}
}