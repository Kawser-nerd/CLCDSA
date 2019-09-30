using static System.Console;
class P
{
	const long M = 1000000007;
	static void Main()
	{
		//var L = int.Parse(ReadLine());
		var L = Int();
		long p = 2, q = 1, r = 1, z;
		for (var i = 0; i < L; i++)
		{
			z = (p + q) * (p - q) % M;
			r = (p * p % M * p + (r << 1) + r) % M;
			q = q * z % M;
			p = p * (p + z) % M;
		}
		if (r < 0) r += M;
		WriteLine(r);
	}
	static int Int()
	{
		var n = 0;
		while (true)
		{
			var c = In.Read() - '0';
			if (0 <= c) n = 10 * n + c;
			else return n;
		}
	}
}