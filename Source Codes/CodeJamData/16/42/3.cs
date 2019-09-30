using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.RedTape
{
    class TestCaseSolver
    {
        int N, K;
        double[] P;
        double ans = 0.0;
        int resMask;

        public void InputData(StreamReader reader)
        {
            var parts = reader.ReadLine().Split(new[] { ' ' });
            N = int.Parse(parts[0]);
            K = int.Parse(parts[1]);

            P = new double[N];

            parts = reader.ReadLine().Split(new[] { ' ' });

            for (int i = 0; i < N; i++)
            {
                P[i] = double.Parse(parts[i], CultureInfo.InvariantCulture);
            }

            Array.Sort(P);
        }

        public double[] Simulate(List<double> P)
        {
            double[] cur = new[] { 1.0 };
            foreach (var p in P)
            {
                double[] next = new double[cur.Length + 1];
                for (int i = 0; i < cur.Length; i++)
                {
                    next[i] += cur[i] * p;
                    next[i + 1] += cur[i] * (1 - p);
                }
                cur = next;
            }
            return cur;
        }

        public void Solve()
        {
            /*for (int mask = 0; mask < (1 << N); mask++)
            {
                var sel = new List<double>();
                for (int i = 0; i < N; i++)
                {
                    if ((mask & (1 << i)) != 0)
                    {
                        sel.Add(P[i]);
                    }
                }
                if (sel.Count == K)
                {
                    double tmp = Simulate(sel)[K / 2];
                    if (tmp > ans)
                    {
                        ans = tmp;
                        resMask = mask;
                    }
                }
            }*/

            for (int take = 0; take <= K; take++)
            {
                var sel = new List<double>();
                for (int i = 0; i < take; i++)
                {
                    sel.Add(P[i]);
                }
                for (int i = N - (K-take); i < N; i++)
                {
                    sel.Add(P[i]);
                }
                double tmp = Simulate(sel)[K / 2];
                if (tmp > ans)
                {
                    ans = tmp;
                }
            }
        }

        public void PrintResult(StreamWriter writer)
        {
            writer.WriteLine(ans.ToString(CultureInfo.InvariantCulture));
        }
    }

    public class Solution
    {
        const string MAIN_FOLDER = "D:\\GCJ";
        const string PROBLEM_NAME = "redtape";
        const int PARALLEL_CASES = 4;

        public static void SolveProblem()
        {
            var reader = new StreamReader(Path.Combine(MAIN_FOLDER, PROBLEM_NAME, "input.txt"));
            var writer = new StreamWriter(Path.Combine(MAIN_FOLDER, PROBLEM_NAME, "output.txt"));

            int caseCnt = int.Parse(reader.ReadLine());
            var solvers = new TestCaseSolver[caseCnt];
            for (int caseNum = 0; caseNum < caseCnt; caseNum++)
            {
                solvers[caseNum] = new TestCaseSolver();
                solvers[caseNum].InputData(reader);
            }

            int batchCnt = (caseCnt + PARALLEL_CASES - 1) / PARALLEL_CASES;
            for (int batchID = 0; batchID < batchCnt; batchID++)
            {
                Console.WriteLine($"Processing batch {batchID + 1} out of {batchCnt}");
                int from = batchID * PARALLEL_CASES;
                int to = Math.Min(caseCnt, (batchID + 1) * PARALLEL_CASES);
                Parallel.For(from, to, caseNum => solvers[caseNum].Solve());
                for (int caseNum = from; caseNum < to; caseNum++)
                {
                    writer.Write($"Case #{caseNum + 1}: ");
                    solvers[caseNum].PrintResult(writer);
                }
            }

            writer.Close();
            reader.Close();
        }
    }
}
