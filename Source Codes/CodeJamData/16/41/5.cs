using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Showdown
{
    class TestCaseSolver
    {
        int N, P, R, S;

        string RecSolve(int N, int P, int R, int S, int posP, int posR, int posS)
        {
            if (N == 0)
            {
                if (P > 0) return "P";
                if (R > 0) return "R";
                return "S";
            }

            int bnd = (1 << (N - 1));
            if (P > bnd || R > bnd || S > bnd)
            {
                return "";
            }

            int PR = bnd - S;
            int PS = bnd - R;
            int RS = bnd - P;

            string pEQ = Math.Min(posP, posR) + "" + Math.Max(posP, posR);
            string rEQ = Math.Min(posR, posS) + "" + Math.Max(posR, posS);
            string sEQ = Math.Min(posP, posS) + "" + Math.Max(posP, posS);

            int newPosP = 0, newPosR = 0, newPosS = 0;
            if (pEQ.CompareTo(rEQ) > 0) newPosP++; else newPosR++;
            if (pEQ.CompareTo(sEQ) > 0) newPosP++; else newPosS++;
            if (rEQ.CompareTo(sEQ) > 0) newPosR++; else newPosS++;

            var res = RecSolve(N - 1, PR, RS, PS, newPosP, newPosR, newPosS);

            if (res == "") return res;

            var ret = "";
            foreach (char c in res.ToCharArray())
            {
                if (c == 'P')
                {
                    ret += posP < posR ? "PR" : "RP";
                }
                if (c == 'R')
                {
                    ret += posR < posS ? "RS" : "SR";
                }
                if (c == 'S')
                {
                    ret += posP < posS ? "PS" : "SP";
                }
            }

            return ret;
        }

        public void InputData(StreamReader reader)
        {
            var parts = reader.ReadLine().Split(new[] { ' ' });
            N = int.Parse(parts[0]);
            R = int.Parse(parts[1]);
            P = int.Parse(parts[2]);
            S = int.Parse(parts[3]);
        }

        public void Solve()
        {   
        }

        public string Simulate(string s)
        {
            if (s.Length == 1)
            {
                return s;
            }
            var ret = "";
            for (int i = 0; i < s.Length; i += 2)
            {
                string t = s.Substring(i, 2);
                if (t == "PP" || t == "RR" || t == "SS")
                {
                    return "";
                }
                if (t == "PR" || t == "RP")
                {
                    ret += "P";
                } else 
                if (t == "PS" || t == "SP")
                {
                    ret += "S";
                } else
                {
                    ret += "R";
                }
            }
            return Simulate(ret);
        }

        public int pw3(int x)
        {
            return x == 0 ? 1 : 3 * pw3(x - 1);
        }

        public void PrintResult(StreamWriter writer)
        {
            /*for (int mask=0; mask<pw3(1<<N); mask++)
            {
                int tmp = mask;
                string s = "";
                int numP = 0, numR = 0, numS = 0;
                for (int i=0; i<(1<<N); i++)
                {
                    int x = tmp % 3;
                    tmp /= 3;
                    s = "PRS"[x] + s;
                    if (x == 0) numP++; else if (x == 1) numR++; else numS++;
                }
                if (numP==P && numR==R && numS==S && Simulate(s) != "")
                {
                    writer.WriteLine(s);
                    return;
                }
            }
            writer.WriteLine("IMPOSSIBLE");*/
            var res = RecSolve(N, P, R, S, 0, 1, 2);
            writer.WriteLine(res.Length == 0 ? "IMPOSSIBLE" : res);
        }
    }

    public class Solution
    {
        const string MAIN_FOLDER = "D:\\GCJ";
        const string PROBLEM_NAME = "showdown";
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
