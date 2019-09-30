using System.Linq;
using System.Numerics;
using static System.Console;
using static System.Math;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split();
	public K()
	{
		var N = F;
		var ps = new Complex[N];
		for (var i = 0; i < N; i++) { var I = G; ps[i] = new Complex(I[0], I[1]); }
		var M = 100000;
		var d = 2 * PI / M;
		var ans = new int[N];
		for (var i = 0; i < M; i++)
		{
			var p = Complex.FromPolarCoordinates(1, i * d);
			var k = -1;
			var r = double.NegativeInfinity;
			for (var j = 0; j < N; j++)
			{
				var tmp = (p * ps[j]).Real;
				if (tmp > r) { r = tmp; k = j; }
			}
			ans[k]++;
		}
		for (var i = 0; i < N; i++) WriteLine(ans[i] / (decimal)M);
	}
}