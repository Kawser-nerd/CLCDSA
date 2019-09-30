using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190308_04 {
    class Program {
        static void Main(string[] args) {
            var line = Console.ReadLine().Split(' ').Select(d => int.Parse(d)).ToArray();
            var a = line[0];
            var b = line[1];
            var q = line[2];
            var s = Enumerable.Repeat(long.MaxValue>>3, a + 2).ToArray();
            var t = Enumerable.Repeat(long.MaxValue>>3, b + 2).ToArray();
            var x = Enumerable.Repeat((long)0, q).ToArray();
            s[0] = long.MinValue>>3;
            t[0] = long.MinValue>>3;
            for (int i = 1; i <= a; i++) {
                s[i] = long.Parse(Console.ReadLine());
            }
            for (int i = 1; i <= b; i++) {
                t[i] = long.Parse(Console.ReadLine());
            }
            for (int i = 0; i < q; i++) {
                x[i] = long.Parse(Console.ReadLine());
            }
            foreach (var item in x) {
                var sn = new int[2];
                var tn = new int[2];
                sn[1] = Array.BinarySearch(s, item);
                tn[1] = Array.BinarySearch(t, item);
                if (sn[1] < 0) {
                    sn[1] = ~sn[1];
                }
                if (tn[1] < 0) {
                    tn[1] = ~tn[1];
                }
                sn[0] = sn[1] - 1;
                tn[0] = tn[1] - 1;
                var ans = long.MaxValue;
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        var temp = Math.Min(Math.Abs(item - s[sn[i]]) + Math.Abs(s[sn[i]] - t[tn[j]]), Math.Abs(item - t[tn[j]]) + Math.Abs(s[sn[i]] - t[tn[j]]));
                        ans = Math.Min(ans, temp);
                    }
                }
                Console.WriteLine(ans);
            }
        }
    }
}