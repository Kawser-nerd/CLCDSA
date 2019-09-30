using System;
using System.Linq;

namespace _20190315_02 {
    class Program {
        static void Main(string[] args) {
            var line = Console.ReadLine().Split(' ').Select(x => double.Parse(x)).ToArray();
            Console.WriteLine(line[0] / line[1]);
        }
    }
}