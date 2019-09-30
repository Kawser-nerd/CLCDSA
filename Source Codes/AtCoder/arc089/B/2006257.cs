using System.Linq;
using static System.Console;
using static System.Math;
class Z { static void Main() => new _K(); }
class _K
{
	int[] G => Strs.Select(int.Parse).ToArray();
	string[] Strs => ReadLine().Split();
	int K, L;
	readonly int[,] sum;
	public _K()
	{
		var I = G;
		K = I[1];
		L = 4 * K;
		sum = new int[L + 1, L + 1];
		for (var i = 0; i < I[0]; i++)
		{
			var S = Strs;
			if (S[2] == "B") Add(int.Parse(S[0]) % (2 * K) + 1, int.Parse(S[1]) % (2 * K) + 1);
			else Add((int.Parse(S[0]) + K) % (2 * K) + 1, int.Parse(S[1]) % (2 * K) + 1);
		}
		for (var x = 0; x < L; x++) for (var y = 0; y <= L; y++) sum[x + 1, y] += sum[x, y];
		for (var x = 0; x <= L; x++) for (var y = 0; y < L; y++) sum[x, y + 1] += sum[x, y];
		var max = 0;
		for (var i = 0; i < K; i++) for (var j = 0; j < K; j++)
			{
				var s = Sum(i, j) + Sum(i + K, j + K);
				max = Max(max, Max(s, I[0] - s));
			}
		WriteLine(max);
	}
	void Add(int x, int y)
	{
		sum[x, y]++;
		sum[x + 2 * K, y]++;
		sum[x + 2 * K, y + 2 * K]++;
		sum[x, y + 2 * K]++;
	}
	int Sum(int i, int j) => sum[i + K, j + K] - sum[i + K, j] - sum[i, j + K] + sum[i, j];
}