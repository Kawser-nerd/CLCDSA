using System;
using System.Linq;

namespace A {
    class Program {
        static void Main (string[] args) {
            var A = Console.ReadLine ();
            var B = Console.ReadLine ();
            if (Math.Max (A.Count (), B.Count ()) == A.Count ()) {
                Console.WriteLine (A);
            } else {
                Console.WriteLine (B);
            }
        }
    }
}