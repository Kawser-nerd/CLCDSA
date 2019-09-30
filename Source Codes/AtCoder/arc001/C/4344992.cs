using System;
using System.Collections.Generic;
using System.Linq;

namespace Program {
    class Program {
        static void Main(string[] args) {
            var cr = new CR();
            var A = cr.i;
            var B = cr.i;

            var ans = 0;
            var buttons = new int[] { 10, 5, 1, -1, -5, -10 };
            while (A != B) {
                var minDistance = Math.Abs(B - A);
                var best_A = A;
                foreach (var dis in buttons) {
                    var a = A + dis;
                    var distance = Math.Abs(B - a);
                    if (distance < minDistance) {
                        minDistance = distance;
                        best_A = a;
                    }
                }
                A = best_A;
                ans++;
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