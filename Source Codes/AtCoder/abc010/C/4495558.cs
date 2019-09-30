using System;
using System.Collections.Generic;
using System.Linq;

namespace C {
    class Program {
        static void Main (string[] args) {
            var input = Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
            var tax = input[0];
            var tay = input[1];
            var tbx = input[2];
            var tby = input[3];
            var T = input[4];
            var V = input[5];

            var n = int.Parse (Console.ReadLine ());
            var xs = new List<int> ();
            var ys = new List<int> ();
            foreach (var i in Enumerable.Range (0, n)) {
                var xy = Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
                xs.Add (xy[0]);
                ys.Add (xy[1]);
            }

            var isGuilty = Enumerable.Range (0, n).Select (i => canAffair (tax, tay, tbx, tby, V, T, xs[i], ys[i])).Any (t => t);
            if (isGuilty) {
                Console.WriteLine ("YES");
            } else {
                Console.WriteLine ("NO");
            }
        }

        static bool canAffair (int tax, int tay, int tbx, int tby, int V, int T, int x, int y) {
            var distanceA = Math.Sqrt (Math.Pow (tax - x, 2) + Math.Pow (tay - y, 2));
            var distanceB = Math.Sqrt (Math.Pow (x - tbx, 2) + Math.Pow (y - tby, 2));
            return (distanceA + distanceB) <= T * V;
        }
    }
}