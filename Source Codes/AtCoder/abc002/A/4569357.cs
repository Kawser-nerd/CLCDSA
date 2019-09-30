using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC002A {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine(Console.ReadLine().Split().Select(Int32.Parse).OrderByDescending(x => x).ToArray()[0]);

        }
    }
}