using System;
using System.Collections.Generic;
using System.Linq;

namespace B {
    class Program {
        static void Main (string[] args) {
            var N = int.Parse (Console.ReadLine ());
            var A = Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
            var noZeroA = A.Where (i => i != 0);
            var average = (int) Math.Ceiling ((double) noZeroA.Sum () / noZeroA.Count ());
            Console.WriteLine (average);
        }
    }
}