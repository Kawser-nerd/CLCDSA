using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190315_04 {
    class Program {
        static void Main(string[] args) {
            var line0 = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var n = line0[0];
            var m = line0[1];
            var line1 = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x => x).ToArray();
            if (n >= m) {
                Console.WriteLine("0");
                return;
            }
            var range = line1.Last() - line1.First();
            var d = new double[m - 1];
            for (int i = 0; i < m - 1; i++) {
                d[i] = line1[i + 1] - line1[i];
            }
            var max = d.OrderByDescending(x => x).Take(n - 1).Sum();
            Console.WriteLine(range-max);
        }
    }
}