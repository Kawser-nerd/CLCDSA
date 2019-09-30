using System;
using System.Collections.Generic;
using System.Linq;

namespace Program {
    class Program {
        static void Main(string[] args) {
            var cr = new CR();
            var N = cr.i;
            var Z = cr.i;
            var W = cr.i;

            int a0 = -1, a1 = 0;
            for (int i = 0; i < N - 1; i++)a0 = cr.i;
            a1 = cr.i;

            int ans;
            if (N == 1) {
                ans = Math.Abs(a1 - W);
            } else {
                var case1 = Math.Abs(a0 - a1);
                var case2 = Math.Abs(a1 - W);
                ans = Math.Max(case1, case2);
            }
            Console.WriteLine(ans);
        }

        private class CR {
            System.IO.TextReader _r;
            Queue<string> _d;
            public CR() { _r = Console.In; _d = new Queue<string>(); }
            string Read() {
                while (_d.Count == 0)
                    foreach (var v in _r.ReadLine().Split(' '))
                        if (v != "")_d.Enqueue(v);
                return _d.Dequeue();
            }
            public int i { get { return int.Parse(Read()); } }
            public string s { get { return Read(); } }
        }
    }
}