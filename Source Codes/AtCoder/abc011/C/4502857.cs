using System;
using System.Collections.Generic;
using System.Linq;

namespace C {
    class Program {
        static void Main (string[] args) {
            var N = int.Parse (Console.ReadLine ());
            var NG1 = int.Parse (Console.ReadLine ());
            var NG2 = int.Parse (Console.ReadLine ());
            var NG3 = int.Parse (Console.ReadLine ());
            var NGs = new List<int> { NG1, NG2, NG3 }.Where (k => k <= N);

            if (NGs.Any (NG => NG == N)) {
                Console.WriteLine ("NO");
                return;
            }

            var subSum = N;
            foreach (var i in Enumerable.Range (0, 100)) {
                if (NGs.All (NG => subSum - 3 != NG)) {
                    subSum -= 3;
                } else if (NGs.All (NG => subSum - 2 != NG)) {
                    subSum -= 2;
                } else if (NGs.All (NG => subSum - 1 != NG)) {
                    subSum -= 1;
                } else {
                    Console.WriteLine ("NO");
                    return;
                }
            }

            if (subSum <= 0) {
                Console.WriteLine ("YES");
                return;
            } else {
                Console.WriteLine ("NO");
                return;
            }

        }
    }
}