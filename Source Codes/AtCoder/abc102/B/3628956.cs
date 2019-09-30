using System;
using System.Linq;

namespace ConsoleApp {

    class Program {
        static void Main(string[] args) {
            var num = int.Parse(Console.ReadLine());
            var numList = Console.ReadLine().Trim().Split().Select(s => int.Parse(s)).ToArray();

            var min = int.MaxValue;
            var max = int.MinValue;

            foreach (var n in numList) {
                min = Math.Min(n, min);
                max = Math.Max(n, max);
            }

            Console.WriteLine(max - min);
        }
    }
}