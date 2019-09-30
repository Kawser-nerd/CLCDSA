using System;

namespace b119A {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine(int.Parse(Console.ReadLine().Split('/')[1]) <= 4 ? "Heisei" : "TBD");
        }
    }
}