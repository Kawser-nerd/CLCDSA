using System;
using System.Collections.Generic;
using System.Linq;

namespace C {
    class Program {
        static void Main (string[] args) {
            var N = int.Parse (Console.ReadLine ());
            var qq = Enumerable.Range (1, 9).Select (i => Enumerable.Range (1, 9).Select (k => i * k).Sum ()).Sum ();
            var forgotten = qq - N;
            var divided = Enumerable.Range (1, 9).Where (i => forgotten / i <= 9 && forgotten % i == 0).ToList ();
            var divisor = divided.Select (i => forgotten / i).ToList ();
            foreach (var i in Enumerable.Range (0, divided.Count)) {
                Console.WriteLine ($"{divided[i]} x {divisor[i]}");
            }
        }
    }
}