using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Factory
{
    class TestCaseSolver
    {
        int N;
        bool[,] can;

        int res;

        bool[,] Remove(bool[,] A, int i, int j)
        {
            int N = A.GetLength(0);
            bool[,] res = new bool[N - 1, N - 1];
            for (int a = 0; a < N; a++)
            {
                for (int b = 0; b < N; b++)
                {
                    if (a != i && b != j)
                    {
                        res[a - (a>i?1:0), b - (b>j?1:0)] = A[a, b];
                    }
                }
            }
            return res;
        }

        int BitCnt(int mask)
        {
            return mask == 0 ? 0 : BitCnt(mask & (mask - 1)) + 1;
        }

        bool HasPerfectMatching(bool[,] A)
        {
            int N = A.GetLength(0);
            for (int mask = 0; mask < (1<<N); mask++)
            {
                int mask2 = 0;
                for (int i = 0; i < N; i++) if ((mask & (1 << i)) != 0)
                        for (int j = 0; j < N; j++) if (A[i, j]) mask2 |= (1 << j);
                if (BitCnt(mask) > BitCnt(mask2))
                {
                    return false;
                }
            }
            return true;
        }

        bool IsGood(bool[,] A)
        {
            if (!HasPerfectMatching(A)) return false;
            int N = A.GetLength(0);
            if (N == 1) return true;
            for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
                    if (A[i, j] && !IsGood(Remove(A, i, j)))
                        return false;
            return true;
        }

        public void InputData(StreamReader reader)
        {
            N = int.Parse(reader.ReadLine());
            can = new bool[N,N];
            for (int i=0; i<N; i++)
            {
                string s = reader.ReadLine();
                for (int j=0;j<N; j++)
                {
                    can[i, j] = (s[j] == '1');
                }
            }
        }

        public void Solve()
        {
            res = N * N;
            for (int mask=0; mask<(1<<(N*N)); mask++)
            {
                bool[,] can2 = new bool[N, N];
                bool ok = true;
                int extra = 0;
                int pos = 0;
                for (int i=0; i<N; i++)
                {
                    for (int j=0; j<N; j++)
                    {
                        can2[i, j] = (mask & (1 << pos)) != 0;
                        if (can[i,j] && !can2[i,j])
                        {
                            ok = false;
                        }
                        if (!can[i,j] && can2[i,j])
                        {
                            extra++;
                        }
                        pos++;
                    }
                }
                if (!ok) continue;
                if (IsGood(can2) && extra < res)
                {
                    res = extra;
                }
            }
        }

        public void PrintResult(StreamWriter writer)
        {
            writer.WriteLine(res);
        }
    }

    public class Solution
    {
        const string MAIN_FOLDER = "D:\\GCJ";
        const string PROBLEM_NAME = "factory";
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
