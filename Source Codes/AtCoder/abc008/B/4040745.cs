using System;
using System.Collections.Generic;
using System.Linq;

namespace B {
    class Program {
        static void Main (string[] args) {
            var n = int.Parse (Console.ReadLine ());
            var s = Enumerable.Range (1, n).Select (i => Console.ReadLine ());

            var ballatBox = new Dictionary<string, int> ();
            foreach (var sItem in s) {
                if (!ballatBox.ContainsKey (sItem)) {
                    ballatBox.Add (sItem, 1);
                } else {
                    ballatBox[sItem] += 1;
                }
            }

            var leader = ballatBox.OrderByDescending (pair => pair.Value).First ().Key;
            Console.WriteLine (leader);
        }
    }
}