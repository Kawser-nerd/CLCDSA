using System;

namespace A {
    class Program {
        static void Main (string[] args) {
            var N = int.Parse (Console.ReadLine ());
            if (N % 2 == 0) {
                var evenSolution = N / 2;
                Console.WriteLine (evenSolution);
            } else {
                var oddSolution = N / 2 + 1;
                Console.WriteLine (oddSolution);
            }
        }
    }
}