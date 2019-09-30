using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gcj2017Qual {
    /// <summary>
    /// Problem C. Bathroom Stalls
    /// </summary>
    /// <remarks>
    /// 1 ≤ K ≤ N.
    /// Small dataset 1
    /// 1 ≤ N ≤ 1000.
    /// Small dataset 2
    /// 1 ≤ N ≤ 10^6.
    /// Large dataset
    /// 1 ≤ N ≤ 10^18.
    /// </remarks>
    class ProgramC {
        private static void Solve(Problem p) {
            // 読込
            var line = p.getNexts().Select(x => long.Parse(x)).ToArray();
            long N = line[0];
            long K = line[1];

            int pow = 0;
            long kcount = K;
            long kmain = 1;
            while (kcount > 1) {
                kcount >>= 1;
                pow++;
                kmain <<= 1;
            }
            N -= K - kmain;
            K = kmain;

            for (int i = 0; i < pow; i++) {
                N >>= 1;
            }

            // 解答
            p.WriteAnswerFullLine($"{N / 2} {(N - 1) / 2}");
        }

        static System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
        static void Main(string[] args) {
            sw.Start();

            Logic(args);

            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }

        private static void Logic(string[] args) {
            Problem p = Problem.createProblem(args);
            if (p == null) return;

            long repeat = p.getNextInt64s().First();

            for (int i = 0; i < repeat; i++) {
                Solve(p);
            }
        }

    }
}
