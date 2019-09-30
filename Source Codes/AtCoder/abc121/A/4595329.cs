using System;
using System.Linq;

namespace Cells {
    class Program {
        static void Main(string[] args) {
            var input1 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var input2 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            var h = input1[0] - input2[0];
            var w = input1[1] - input2[1];
            
            Console.WriteLine(h * w);
        }
    }
}