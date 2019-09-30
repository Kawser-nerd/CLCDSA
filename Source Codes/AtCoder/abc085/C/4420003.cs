using System;
using System.Collections.Generic;
using System.Linq;

namespace Project {
    class Program {
        static void Main(string[] args) {
            var cr = new CR();

            var N = cr.i;
            var Y = cr.i;

            for (var z = 0; z <= N; z++) {
                for (var y = 0; y <= N - z; y++) {
                    var x_yen = Y - (5000 * y) - (1000 * z);
                    if (x_yen % 10000 != 0)continue;
                    var x = x_yen / 10000;
                    if (x + y + z == N) {
                        Console.WriteLine(x + " " + y + " " + z);
                        return;
                    }
                }
            }

            Console.WriteLine("-1 -1 -1");
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