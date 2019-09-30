using System;

namespace B {
    class Program {
        static void Main (string[] args) {
            var a = int.Parse (Console.ReadLine ());
            var b = int.Parse (Console.ReadLine ());
            var forward = Math.Abs (a - b);
            var min = Math.Min (forward, 10 - forward);
            Console.WriteLine (min);
        }
    }
}