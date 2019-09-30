using System;

namespace AtCoder
{
	class Programs
	{
		static void Main ()
		{
			var n = int.Parse (Console.ReadLine ());
			var k = int.Parse (Console.ReadLine ());
			var a = Array.ConvertAll (Console.ReadLine ().Split (), int.Parse);
			long ans = 0;
			for (int i = 0; i < n; i++) 
			{
				if (k - a [i] < a [i]) ans += k - a [i];
				else ans += a [i];
			}
			Console.WriteLine (2*ans);
		}
	}
}