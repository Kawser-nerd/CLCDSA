using System;
using System.Linq;

namespace a {
    class Program {
        static void Main (string[] args) {
            var xs = Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
            Console.WriteLine (xs[1] / xs[0]);
        }
    }
}