using System;
using System.Linq;

namespace b120B {
    class Program {
        static void Main(string[] args) {
            var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var a = input[0];
            var b = input[1];
            var k = input[2];

            for (int i = Math.Min(a,b); i > 0; i--) {
                if (a % i == 0 && b % i == 0) {
//                    Console.WriteLine(i);
                    k--;
                    if (k == 0) {
                        Console.WriteLine(i);
                        return;
                    }
                }
            }
        }
    }
}