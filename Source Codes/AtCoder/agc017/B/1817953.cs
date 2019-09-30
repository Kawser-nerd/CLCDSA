using System.Linq;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	public K() { WriteLine(Solve() ? "YES" : "NO"); }
	bool Solve()
	{
		var I = ReadLine().Split().Select(int.Parse).ToArray();
		int N = I[0], A = I[1], B = I[2], C = I[3], D = I[4];
		long d = B - A, n = N - 1, s = C + D, l = n * C - d, r = n * D - d;
		for (var k = 0; k <= N; k++)
		{
			var t = s * k;
			if (l <= t && t <= r) return true;
		}
		return false;
	}
}