using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.CountingSheep
{
    class TestCaseSolver
    {
        bool[] seen = new bool[10];
        int seenCnt = 0;

        long N, ans;

        public void InputData(StreamReader reader)
        {
            N = long.Parse(reader.ReadLine());
        }

        public void Solve()
        {
            if (N == 0)
            {
                ans = -1;
                return;
            }

            long cur = 0;
            while (true)
            {
                cur += N;
                long tmp = cur;
                while (tmp>0)
                {
                    if (!seen[tmp%10])
                    {
                        seen[tmp % 10] = true;
                        seenCnt++;
                    }
                    tmp /= 10;
                }
                if (seenCnt == 10)
                {
                    ans = cur;
                    break;
                }
            }
        }

        public void PrintResult(StreamWriter writer)
        {
            writer.WriteLine(ans == -1 ? "INSOMNIA" : "" + ans);
        }
    }

    public class Solution
    {
        const string MAIN_FOLDER = "D:\\GCJ";
        const string PROBLEM_NAME = "sheep";
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
                    writer.Write($"Case #{caseNum + 1}: ");
                    solvers[caseNum].PrintResult(writer);
                }
            }

            writer.Close();
            reader.Close();
        }
    }
}
