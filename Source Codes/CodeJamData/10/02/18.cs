using System;
using System.Linq;
using System.Numerics;

class Program
{
	static void Main()
	{
		var cnt = int.Parse(Console.ReadLine());
		for (var i = 0; i < cnt; )
		{
			var data = Console.ReadLine().Split(' ');
			int count;
			var nums = new BigInteger[count = int.Parse(data[0])];

			for (var j = 0; j < count; j++)
				nums[j] = BigInteger.Parse(data[j + 1]);

			var d = nums[1] - nums[0];
			if (d.Sign == -1) d = -d;
			for (var j = 2; j < count; j++)
			{
				var t = nums[j] - nums[0];
				if (t.Sign == -1) t = -t;
				d = BigInteger.GreatestCommonDivisor(d, t);
			}

			var ans = nums[0] % d;
			Console.WriteLine("Case #{0}: {1}", ++i, ans.IsZero ? "0" :  (d - ans).ToString());
		}
	}
}
