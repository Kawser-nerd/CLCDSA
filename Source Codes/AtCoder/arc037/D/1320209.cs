using static System.Console;
class P
{
	const long M = 1000000007;
	static readonly long[][] a = new[] {
		new[]{ 2L, 1L, 1L },
		new[]{ 559412125L, 508874309L, 402031616L },
		new[]{ 757061558L, 25523471L, 180309632L },
		new[]{ 791024759L, 651000389L, 497626005L },
		new[]{ 156690675L, 429144592L, 507499122L },
		new[]{ 388240918L, 836011381L, 130632838L },
		new[]{ 247226105L, 678004455L, 684065868L },
		new[]{ 614118175L, 318267172L, 631326023L },
		new[]{ 391071408L, 383098699L, 164787756L },
		new[]{ 427952049L, 846699181L, 991096575L },
		new[]{ 651077913L, 641710575L, 831145010L }
	};
	static void Main()
	{
		var L = int.Parse(ReadLine());
		var b = a[L / 10000];
		long p = b[0], q = b[1], r = b[2], z;
		L %= 10000;
		for (var i = 0; i < L; i++)
		{
			/*if (i % 10000 == 0)
			{
				if (p < 0) p += M;
				if (q < 0) q += M;
				if (r < 0) r += M;
				WriteLine($"new[]{{{p}L, {q}L, {r}L}},");
			}*/
			z = (p + q) * (p - q) % M;
			r = (p * p % M * p + (r << 1) + r) % M;
			q = q * z % M;
			p = p * (p + z) % M;
		}
		if (r < 0) r += M;
		WriteLine(r);
	}
}