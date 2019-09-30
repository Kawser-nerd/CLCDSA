using System;
using System.Collections.Generic;
using System.Linq;

namespace b {
    class Program {
        static void Main (string[] args) {
            var n = int.Parse (Console.ReadLine ());
            var ts = new List<int> ();
            foreach (var i in Enumerable.Range (0, n)) {
                var t = int.Parse (Console.ReadLine ());
                ts.Add (t);
            }

            Console.WriteLine (ts.Min ());
        }
    }
}