using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190308_01 {
    class Program {
        static void Main(string[] args) {
            var s = Console.ReadLine();
            var compare = "2019/04/30";
            if (s.CompareTo(compare) == 1) {
                Console.WriteLine("TBD");
            } else {
                Console.WriteLine("Heisei");
            }
        }
    }
}