using System;
using System.Linq;

namespace _20190308_03 {
    class Program {
        static void Main(string[] args) {
            var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var n = line[0];
            var a = line[1];
            var b = line[2];
            var c = line[3];
            var bamboo = new int[n];
            for (int i = 0; i < n; i++) {
                bamboo[i] = int.Parse(Console.ReadLine());
            }
            var mp = int.MaxValue;
            for (int i = 0; i < Math.Pow(4, n); i++) {
                var val = Enumerable.Repeat(0, 3).ToArray();
                var m = 0;
                for (int j = 0; j < n; j++) {
                    var index = (i >> (j * 2) & 0x3);
                    if (index != 3) {
                        m += 10;
                        val[index] += bamboo[j];
                    }
                }
                if (val.Min() != 0) {
                    m += Math.Abs(val[0] - a) + Math.Abs(val[1] - b) + Math.Abs(val[2] - c) - 30;
                    mp = Math.Min(mp, m);
                }
            }
            Console.WriteLine(mp);
        }
    }
}