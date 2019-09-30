using System;
using System.Linq;
using System.Collections.Generic;
namespace AtCoder
{
	class Programs
	{
		static void Main ()
		{
			var inp = Array.ConvertAll (Console.ReadLine ().Split (), long.Parse);
			var a = Array.ConvertAll (Console.ReadLine ().Split (), long.Parse);
			var b = new long[a.Count () + 1];
			b [0] = 0;
			for (int i = 0; i < a.Count (); i++) {
				b [i + 1] = b [i] + a [i];
			}
			var list = new List<long> ();
			for (int i = 0; i < b.Count (); i++) {
				list.Add (b [i] % inp [1]);
			}
			list = list.OrderBy (f => f).ToList ();
			long check = -1;
			long count = 0;
			long ans = 0;
			for (int i = 0; i < list.Count (); i++) {
				if (check != list [i]) {
					ans += count * (count - 1) / 2;
					check = list [i];
					count = 1;
				} else {
					count++;
				}
			}
			ans += count * (count - 1) / 2;
			Console.WriteLine (ans);
		}
	}
}