using System;
using System.Linq;
using System.Collections.Generic;
namespace AtCoder
{
	class Programs
	{
		static void Main ()
		{
			var nx = Array.ConvertAll (Console.ReadLine ().Split (), int.Parse);
			var x = Array.ConvertAll (Console.ReadLine ().Split (), int.Parse);
			var dist = new List<int> ();
			for (int i = 0; i < x.Length; i++) {
				dist.Add((int)Math.Abs (x[i] - nx [1]));
			}
			int D = dist [0];
			for (int i = 0; i < dist.Count (); i++) {
				D = gcd (dist [i], D);
			}
			Console.WriteLine (D);
		}
		public static int gcd(int a, int b)
		{
			if (a < b)
				return gcd (b, a);
			while (b > 0) {
				int temp = a % b;
				a = b;
				b = temp;
			}
			return a;
		}
	}
}