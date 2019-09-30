using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190308_07 {
    class Program {
        static void Main(string[] args) {
            var n = int.Parse(Console.ReadLine());
            var line = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
            var a = GCD(line[0], line[1]);
            for (int i = 2; i < n; i++) {
                a = GCD(a, line[i]);
            }
            Console.WriteLine(a);
        }

        static long GCD(long a, long b) {
            if (a < b)
                GCD(b, a);
            while (b != 0) {
                var remainder = a % b;
                a = b;
                b = remainder;
            }
            return a;
        }

    }
}