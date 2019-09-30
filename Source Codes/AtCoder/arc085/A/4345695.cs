using System;
using System.Collections.Generic;
using System.Linq;

namespace Program {
    class Program {
        static void Main(string[] args) {
            var cr = new CR();
            var N = cr.i;
            var M = cr.i;

            var count = Math.Pow(2, M);
            var ans = (M * 1900 + (N - M) * 100) * count;

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