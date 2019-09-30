using System;
using System.Linq;

namespace C
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var n = int.Parse(Console.ReadLine());
			var cn = new int[n - 1];
			var sn = new int[n - 1];
			var fn = new int[n - 1];
			for (var i = 0; i < n - 1; i++)
			{
				var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
				cn[i] = line[0];
				sn[i] = line[1];
				fn[i] = line[2];
			}

			var result = new int?[n];
			result[n - 1] = 0;
			result[n - 2] = sn[n - 2] + cn[n - 2];
			for (var i = n - 3; i >= 0; i--)
			{
				var tmp = sn[i] + cn[i];
				for (var j = 0; i + j + 1 < n - 1; j++)
				{
					if (tmp <= sn[i + j + 1])
					{
						result[i] = result[i + j + 1];
						break;
					}

					tmp += (fn[i + j + 1] - tmp % fn[i + j + 1]) % fn[i + j + 1] + cn[i + j + 1];
				}

				if (result[i] == null) { result[i] = tmp; }
			}

			foreach (var r in result) { Console.WriteLine(r); }
		}
	}
}