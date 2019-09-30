using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
	class Programs
	{
		static void Main ()
		{
			var inp = Array.ConvertAll (Console.ReadLine ().Split (), int.Parse);
			var list = new List<Tuple<int,int>> ();
			for (int i = 0; i < inp [1]; i++) {
				var temp = Array.ConvertAll (Console.ReadLine ().Split (), int.Parse);
				list.Add (new Tuple<int,int> (temp [0], temp [1]));
			}
			list = list.OrderBy (f => f.Item2).ToList ();
			int removeBridge = list [0].Item2-1;
			int ans = 1;
			for (int i = 1; i < list.Count (); i++) {
				if (list [i].Item1 > removeBridge) {
					removeBridge = list [i].Item2 - 1;
					ans++;
				}
			}
			Console.WriteLine (ans);
		}
	}
}