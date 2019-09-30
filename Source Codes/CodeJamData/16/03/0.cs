using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Jamcoin
{
    class TestCaseSolver
    {
        int N, J;

        public void InputData(StreamReader reader)
        {
            var parts = reader.ReadLine().Split(new[] { ' ' });
            N = int.Parse(parts[0]);
            J = int.Parse(parts[1]);
        }

        public void Solve()
        {
        }

        public void PrintResult(StreamWriter writer)
        {
            int n = N / 2;
            for (int mask = (1<<(n-1)) + 1; mask < (1<<n); mask += 2)
            {
                string s = "";
                for (int i = 0; i < n; i++)
                {
                    s += (mask & (1 << i)) == 0 ? "0" : "1";
                }
                writer.Write(s + s);
                for (int x = 2; x <= 10; x++)
                {
                    long div = 0;
                    long pw = 1;
                    for (int i = s.Length - 1; i >= 0; i--)
                    {
                        if (s[i] == '1')
                        {
                            div += pw;
                        }
                        pw *= x;
                    }
                    writer.Write(" " + div);
                }
                writer.WriteLine();
                J--;
                if (J == 0) break;
            }
        }
    }

    public class Solution
    {
        const string MAIN_FOLDER = "D:\\GCJ";
        const string PROBLEM_NAME = "jamcoin";
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
                    writer.WriteLine($"Case #{caseNum + 1}:");
                    solvers[caseNum].PrintResult(writer);
                }
            }

            writer.Close();
            reader.Close();
        }
    }
}
