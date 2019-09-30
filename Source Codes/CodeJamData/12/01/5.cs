using System;

namespace jam_a
{
	class Program
	{
		static void Main()
		{
			var from = new[] {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
							//'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
			var t = int.Parse(Console.ReadLine());
			for (var i = 0; i < t; i++)
			{
				var s = Console.ReadLine();
				var ans = "";
				foreach (var c in s)
					if (c == ' ')
						ans += ' ';
					else
						ans += from[c - 'a'];
				Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, ans));
			}
		}
	}
}
