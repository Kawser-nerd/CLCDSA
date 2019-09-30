using System;
using System.Linq;

namespace A {
    class Program {
        static void Main (string[] args) {
            var input = Console.ReadLine ().Split (' ').Select (oneChar => int.Parse (oneChar)).ToList ();
            var s = input[0];
            var t = input[1];
            Console.WriteLine (t - s + 1);
        }
    }
}