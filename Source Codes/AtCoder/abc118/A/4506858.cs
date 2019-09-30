using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190308_05 {
    class Program {
        static void Main(string[] args) {
            var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            if (line[1] % line[0] == 0) {
                Console.WriteLine(line.Sum());
            } else {
                Console.WriteLine(line[1] - line[0]);
            }
        }
    }
}