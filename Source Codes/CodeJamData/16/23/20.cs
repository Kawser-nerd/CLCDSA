using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    struct D {
        public string a, b;
    }

    static int Calc(List<D> xs) {
        int n = xs.Count;

        int ans = 0;
        var real = new bool[n];
        for (int i = 0; i < (1 << n); i++) {
            var fst = new HashSet<string>();
            var snd = new HashSet<string>();

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    real[j] = true;
                    fst.Add(xs[j].a);
                    snd.Add(xs[j].b);
                }
                else {
                    real[j] = false;
                }
            }

            int x = 0;
            for (int j = 0; j < n; j++) {
                if (real[j]) continue;

                if (fst.Contains(xs[j].a) && snd.Contains(xs[j].b)) {
                    x++;
                }
            }

            ans = Math.Max(ans, x);
        }
        return ans;
    }

    static void Main() {
        int t = ReadInt();
        for (int i = 0; i < t; i++) {
            int n = ReadInt();
            var xs = new List<D>();
            for (int j = 0; j < n; j++) {
                var ss = ReadStrings();
                xs.Add(new D { a = ss[0], b = ss[1] });
            }

            Console.WriteLine("Case #{0}: {1}", i+1, Calc(xs));
        }
    }
}
