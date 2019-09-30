using System;
using System.Linq;

namespace _20190315_03 {
    class Program {
        static void Main(string[] args) {
            Console.ReadLine();
            var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderByDescending(x => x).ToArray();
            var longest = line[0];
            var sum = line.Skip(1).Sum();
            if (longest < sum) {
                Console.WriteLine("Yes");
            } else {
                Console.WriteLine("No");
            }
        }
    }
}