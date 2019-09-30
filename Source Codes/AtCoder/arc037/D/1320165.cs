using static System.Console;
class P
{
	const long M = 1000000007;
	static long[] x = { 2, 1, 1L };
	static void Main()
	{
		var L = int.Parse(ReadLine());
		for (var i = 0; i < L; i++)
		{
			long a = x[0], p = (a * a - x[1] * x[1]) % M;
			x[0] = a * (a + p) % M;
			x[1] = x[1] * p % M;
			x[2] = (a * a % M * a % M + 3 * x[2]) % M;
		}
		if (x[2] < 0) x[2] += M;
		WriteLine(x[2]);
	}
}