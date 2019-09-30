using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190315_08 {
    class Program {
        static void Main(string[] args) {
            var line = Console.ReadLine().Split(' ').Select(d => int.Parse(d)).ToArray();
            var s = line[0];
            var a = new List<int>() { s };
            for (int i = 0; i < int.MaxValue; i++) {
                var a_i = f(a[i]);
                if (a.Any(x => x == a_i)) {
                    Console.WriteLine(i + 2);
                    return;
                }
                a.Add(a_i);
            }
        }

        static int f(int n) {
            if ((n & 1) == 0) {
                return n >> 1;
            }
            return 3 * n + 1;
        }
    }
}