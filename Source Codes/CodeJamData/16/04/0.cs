using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Fractiles
{
    class TestCaseSolver
    {
        long K, C, S;

        public void InputData(StreamReader reader)
        {
            var parts = reader.ReadLine().Split(new[] { ' ' });
            K = long.Parse(parts[0]);
            C = long.Parse(parts[1]);
            S = long.Parse(parts[2]);
        }

        public void Solve()
        {
        }

        public void PrintResult(StreamWriter writer)
        {
            long need = (K + C - 1) / C;
            if (need > S)
            {
                writer.WriteLine(" IMPOSSIBLE");
                return;
            }
            for (int i = 0; i < need; i++)
            {
                long pw = 1, pos = 0;
                for (int j = 0; j < C; j++)
                {
                    long dig = i * C + j;
                    if (dig >= K) dig = 0;
                    pos += pw * dig;
                    pw *= K;
                }
                writer.Write(" " + (pos + 1));
            }
            writer.WriteLine();
        }
    }

    public class Solution
    {
        const string MAIN_FOLDER = "D:\\GCJ";
        const string PROBLEM_NAME = "fractiles";
        const int PARALLEL_CASES = 4;

        public static void SolveProblem() {
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
                Console.WriteLine($"Processing batch {batchID+1} out of {batchCnt}");
                int from = batchID * PARALLEL_CASES;
                int to = Math.Min(caseCnt, (batchID + 1) * PARALLEL_CASES);
                Parallel.For(from, to, caseNum => solvers[caseNum].Solve());
                for (int caseNum = from; caseNum < to; caseNum++)
                {
                    writer.Write($"Case #{caseNum + 1}:");
                    solvers[caseNum].PrintResult(writer);
                }
            }

            writer.Close();
            reader.Close();
        }
    }
}
