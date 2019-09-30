using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.SenateEvacuation
{
    class TestCaseSolver
    {
        int N;
        int[] cnt;
        int sum;

        List<string> res = new List<string>();

        public void InputData(StreamReader reader)
        {
            N = int.Parse(reader.ReadLine());
            var parts = reader.ReadLine().Split(new[] { ' ' });
            cnt = new int[N];
            for (int i = 0; i < N; i++)
            {
                cnt[i] = int.Parse(parts[i]);
                sum += cnt[i];
            }
        }

        public string EvacMax()
        {
            int max = 0, maxPos = -1;
            for (int i = 0; i < N; i++)
            {
                if (cnt[i] > max)
                {
                    max = cnt[i];
                    maxPos = i;
                }
            }
            cnt[maxPos]--;
            sum--;
            return "" + (char)('A' + maxPos);
        }

        public void Solve()
        {
            while (sum > 0)
            {
                string s = "";
                if (sum % 2 == 0)
                {
                    s += EvacMax();
                }
                if (sum % 1 == 0)
                {
                    s += EvacMax();
                }
                res.Add(s);
            }
        }

        public void PrintResult(StreamWriter writer)
        {
            for (int i = 0; i < res.Count; i++) {
                writer.Write(" " + res[i]); 
            }
            writer.WriteLine();
        }
    }

    public class Solution
    {
        const string MAIN_FOLDER = "D:\\GCJ";
        const string PROBLEM_NAME = "evacuation";
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
