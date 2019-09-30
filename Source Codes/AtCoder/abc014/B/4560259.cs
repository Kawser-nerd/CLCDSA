using System;
using System.Collections.Generic;
using System.Linq;

namespace B {
    class Program {
        static void Main (string[] args) {
            var nX = Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
            var n = nX[0];
            var X = nX[1];

            var a = Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
            var mask = (int) Math.Pow (2, n + 1) - 1;
            var sum = Enumerable.Range (0, n).Where (i => (X >> i) % 2 == 1).Select (i => a[i]).Sum ();
            Console.WriteLine (sum);
        }
    }
}