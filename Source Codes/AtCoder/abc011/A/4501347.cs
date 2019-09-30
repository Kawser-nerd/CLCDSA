using System;

namespace A {
    class Program {
        static void Main (string[] args) {
            var N = int.Parse (Console.ReadLine ());
            Console.WriteLine (N % 12 + 1);
        }
    }
}