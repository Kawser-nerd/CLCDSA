using System.Linq;
using static System.Console;
class K
{
	static void Main()
	{
		var I = ReadLine().Split().Select(long.Parse).ToArray();
		long N = I[0], K = I[1], sum = 0L;
		for (var b = K + 1; b <= N; b++)
		{
			var q = N % b;
			sum += (b - K) * (N / b);
			if (K <= q) sum += q - K + 1;
			if (K == 0) sum--;
		}
		WriteLine(sum);
	}
}