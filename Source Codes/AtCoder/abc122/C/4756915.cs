using System;
using System.Linq;

namespace b122C {
    class Program {
        static void Main(string[] args) {
            var input = Console.ReadLine();
            var sp = input.Split(' ');
            var n = int.Parse(sp[0]);
            var q = int.Parse(sp[1]);
            var s = Console.ReadLine();

            var x = 0;
            var t = new int[n];
            for (int i = 0; i < n - 1; i++) {
                t[i + 1] = t[i] + (s.Substring(i, 2) == "AC" ? 1 : 0);
            }

            for (int i = 0; i < q; i++) {
                var lr = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                var l = lr[0] - 1;
                var r = lr[1] - 1;


                Console.WriteLine(t[r] - t[l]);
            }
        }
    }
}