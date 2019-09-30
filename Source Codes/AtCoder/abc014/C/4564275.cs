using System;
using System.Collections.Generic;
using System.Linq;

namespace C {
    class Program {
        static void Main (string[] args) {
            var n = int.Parse (Console.ReadLine ());
            var a = new List<int> ();
            var b = new List<int> ();
            foreach (var i in Enumerable.Range (0, n)) {
                var ab = Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
                a.Add (ab[0]);
                b.Add (ab[1]);
            }

            var k = 1000000;
            var diff = new int[(k + 1) + 1];
            foreach (var i in Enumerable.Range (0, n)) {
                diff[a[i]] += 1;
                diff[b[i] + 1] -= 1;
            }

            var cum = new int[(k + 1) + 1];
            cum[0] = diff[0];
            foreach (var i in Enumerable.Range (1, k + 1)) {
                cum[i] = diff[i] + cum[i - 1];
            }
            Console.WriteLine (cum.Max ());
        }
    }
}