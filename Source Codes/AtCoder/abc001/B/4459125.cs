using System;

namespace ABC001B {
    class Program {
        static void Main(string[] args) {
            var m = int.Parse(Console.ReadLine());
            if (m > 70000) {
                Console.WriteLine("89");
            } else if (m >= 35000 && m <= 700000) {
                Console.WriteLine((int)(((m / 1000 - 30) / 5) + 80));
            } else if (m >= 6000 && m <= 30000) {
                Console.WriteLine((int)(m / 1000 + 50));
            }else if (m >= 100 && m <= 5000) {
                Console.WriteLine($"{(int)(m / 100):D2}");
            } else {
                Console.WriteLine("00");
            }
        }
    }
}