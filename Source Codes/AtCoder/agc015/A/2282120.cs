using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC015_A {
    class Program {
        static void Main(string[] args) {
            var s = Console.ReadLine().Split();
            var n = long.Parse(s[0]);
            var a = long.Parse(s[1]);
            var b = long.Parse(s[2]);
            if (a > b) {
                Console.WriteLine(0);
                return;
            }else if (n == 1) {
                if (a == b) {
                    Console.WriteLine(1);
                } else {
                    Console.WriteLine(0);
                }
                return;
            } else {
                Console.WriteLine(((n - 2) * (b - a) + 1));
                return;
            }
        }
    }
}