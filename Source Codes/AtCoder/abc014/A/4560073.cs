using System;

namespace A {
    class Program {
        static void Main (string[] args) {
            var a = int.Parse (Console.ReadLine ());
            var b = int.Parse (Console.ReadLine ());
            var rest = a % b;
            var solve = 0;
            if (rest != 0) {
                solve = b - rest;
            }
            Console.WriteLine (solve);
        }
    }
}