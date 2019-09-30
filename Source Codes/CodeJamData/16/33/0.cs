using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.FashionPolice
{
    class TestCaseSolver
    {
        int J, P, S, K;
        public void InputData(StreamReader reader)
        {
            var parts = reader.ReadLine().Split(new[] { ' ' });
            J = int.Parse(parts[0]);
            P = int.Parse(parts[1]);
            S = int.Parse(parts[2]);
            K = int.Parse(parts[3]);
            if (K > S)
            {
                K = S;
            }
        }

        public void Solve()
        {
        }

        public void PrintResult(StreamWriter writer)
        {
            writer.WriteLine(J * P * K);
            for (int i = 1; i <= J; i++)
            {
                for (int j = 1; j <= P; j++)
                {
                    for (int k = 1; k <= K; k++)
                    {
                        writer.WriteLine(i + " " + j + " " + ((i + j + k) % S + 1));
                    }
                }
            }
        }
    }

    public class Solution
    {
        const string MAIN_FOLDER = "D:\\GCJ";
        const string PROBLEM_NAME = "fashion";
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
