using System;
using System.Linq;

namespace _20190315_06 {
    class Program {
        static void Main(string[] args) {
            var line = Console.ReadLine().Split(' ').Select(d => int.Parse(d)).ToArray();
            Console.WriteLine(line[0] * line[1] / 2);
        }
    }
}