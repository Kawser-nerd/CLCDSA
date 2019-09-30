using System;
using System.Linq;

namespace b120A {
    class Program {
        static void Main(string[] args) {
            var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var a = input[0];
            var b = input[1];
            var c = input[2];
            Console.WriteLine(Math.Min(c,b/a));
        }
    }
}