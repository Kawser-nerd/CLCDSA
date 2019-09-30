using static System.Console;
class P
{
	const long M = 1000000007;
	static void Main()
	{
		var L = int.Parse(ReadLine());
		long p = 2, q = 1, r = 1, z;
		for (var i = 0; i < L; i++)
		{
			z = (p + q) * (p - q) % M;
			r = (p * p % M * p + 3 * r) % M;
			q = q * z % M;
			p = p * (p + z) % M;
		}
		if (r < 0) r += M;
		WriteLine(r);
	}
}