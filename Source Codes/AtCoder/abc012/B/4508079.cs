using System;

namespace B {
    class Program {
        static void Main (string[] args) {
            var N = int.Parse (Console.ReadLine ());
            var hh = N / (60 * 60);
            var mmss = N % (60 * 60);
            var mm = mmss / 60;
            var ss = mmss % 60;
            Console.WriteLine ($"{hh:00}:{mm:00}:{ss:00}");
        }
    }
}