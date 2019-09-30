using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Slides
{
    class TestCaseSolver
    {
        int B;
        long M;

        bool can;
        char[][] res;

        public void InputData(StreamReader reader)
        {
            var parts = reader.ReadLine().Split(new[] { ' ' });
            B = int.Parse(parts[0]);
            M = long.Parse(parts[1]);
        }

        public void Solve()
        {
            if (M > 1L<<(B-2))
            {
                can = false;
                return;
            }

            res = new char[B][];
            can = true;
            for (int i=0;i<B; i++)
            {
                res[i] = new char[B];
                for (int j=0; j<B; j++)
                {
                    res[i][j] = '0';
                }
            }

            for (int i = 1; i < B; i++)
            {
                for (int j = i + 1; j < B; j++)
                {
                    res[i][j] = '1';
                }
            }
            for (int i = 1; i < B-1; i++)
            {
                if (M>=(1L<<(B-i-2)))
                {
                    res[0][i] = '1';
                    M -= 1L << (B - i - 2);
                }
            }
            if (M>0)
            {
                res[0][B - 1] = '1';
            }
        }

        public void PrintResult(StreamWriter writer)
        {
            if (can)
            {
                writer.WriteLine("POSSIBLE");
                for (int i=0;i<B; i++)
                {
                    for (int j=0; j<B; j++)
                    {
                        writer.Write(res[i][j]);
                    }
                    writer.WriteLine();
                }
            } else
            {
                writer.WriteLine("IMPOSSIBLE");
            }
        }
    }

    public class Solution
    {
        const string MAIN_FOLDER = "D:\\GCJ";
        const string PROBLEM_NAME = "slides";
        const int PARALLEL_CASES = 1;

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
