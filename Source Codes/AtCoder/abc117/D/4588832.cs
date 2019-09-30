using System;
using System.Linq;

namespace _20190315_05 {
    class Program {
        static void Main(string[] args) {
            var line0 = Console.ReadLine().Split(' ').Select(d => long.Parse(d)).ToArray();
            var n = line0[0];
            var k = line0[1];
            var line1 = Console.ReadLine().Split(' ').Select(d => long.Parse(d)).ToArray();
            long x = 0;
            for (int j = 40; j >= 0; j--) {
                if (line1.Where(d => ((d >> j) & 1) == 1).Count() <= n / 2) {
                    x += (long)1 << j;
                    //Console.WriteLine(j);
                }
                if (x > k) {
                    x -= (long)1 << j;
                    //Console.WriteLine(j + ":ok");
                    //continue;
                }
            }
            //Console.WriteLine(x);
            long ans = line1.Select(d => d ^ x).Sum();
            Console.WriteLine(ans);
        }
    }
}