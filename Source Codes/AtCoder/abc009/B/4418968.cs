using System;
using System.Collections.Generic;
using System.Linq;

namespace B {
    class Program {
        static void Main (string[] args) {
            var N = int.Parse (Console.ReadLine ());
            var A = new List<int> ();
            foreach (var i in Enumerable.Range (0, N)) {
                A.Add (int.Parse (Console.ReadLine ()));
            }

            var sorted = A.Distinct ().OrderByDescending (x => x);
            if (sorted.Count () == 1) {
                Console.WriteLine (sorted.First ());
            } else {
                Console.WriteLine (sorted.Take (2).Last ());
            }
        }
    }
}