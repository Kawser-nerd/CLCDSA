using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gcj2017Qual {
    /// <summary>
    /// Problem B. Tidy Numbers
    /// </summary>
    class ProgramB {

        private static void Solve(Problem p) {
            // 読込
            char[] N = p.getNexts().First().ToCharArray();
            for (int i = N.Length - 1; i >= 0; i--) {
                if(N.Take(i).Any(x => x > N[i] || x == '0')){
                    // 以降の桁すべてを9で埋める
                    for (int j = i; j < N.Length; j++) {
                        N[j] = '9';
                    }
                    N[i - 1]--;
                }
            }
            string answer = new string(N.SkipWhile(x => x == '0').ToArray());

                // 解答
            p.WriteAnswerFullLine(answer);
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
