using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1CProblemB
{
    class Program
    {
        struct Interval: IComparable<Interval>
        {
            public int S;
            public int E;
            public int P;

            public int CompareTo(Interval other)
            {
                return S.CompareTo(other.S);
            }
        }

        static int getCount(List<int> C, int time)
        {
            int s = 0;
            int res = 0;
            for (int i = C.Count - 1; i >= 0; --i)
            {
                s += C[i];
                res += 2;
                if (s >= time)
                    return res;
            }
            return res;
        }

        static void SolveAllTests(TextReader input, TextWriter output)
        {
            int TT = int.Parse(input.ReadLine());
            for (int testCase = 1; testCase <= TT; testCase++)
            {
                string[] s = input.ReadLine().Split();
                int A1 = int.Parse(s[0]);
                int A2 = int.Parse(s[1]);

                int[] TF = new int[2];
                Interval[] t = new Interval[A1 + A2];
                for (int i = 0; i < A1 + A2; ++i)
                {
                    s = input.ReadLine().Split();
                    t[i].S = int.Parse(s[0]);
                    t[i].E = int.Parse(s[1]);
                    t[i].P = (i < A1)?1:0;
                    TF[t[i].P] += t[i].E - t[i].S;
                }

                int freeT = 0;
                Array.Sort(t);
                List<int>[] C = new List<int>[2];
                C[0] = new List<int>();
                C[1] = new List<int>();
                int[] TC = new int[2];
                int minRes = 0;
                for (int i = 1; i < t.Length; ++i)
                {
                    int ilen = t[i].S - t[i - 1].E;
                    if (t[i - 1].P == t[i].P)
                    {
                        if (ilen > 0)
                            C[t[i].P].Add(ilen);
                        TC[t[i].P] += ilen;
                    }
                    else
                    {
                        minRes++;
                        freeT += ilen;
                    }
                }

                int wLen = 24 * 60 - t[t.Length - 1].E + t[0].S;

                if (t[0].P == t[t.Length - 1].P)
                {
                    if (wLen > 0)
                        C[t[0].P].Add(wLen);
                    TC[t[0].P] += wLen;
                }
                else
                {
                    minRes++;
                    freeT += wLen;
                }

                System.Diagnostics.Debug.Assert(TF[0] + TC[0] + TF[1] + TC[1] + freeT == 60 * 24);
                C[0].Sort();
                C[1].Sort();

                int res = 0;
                if (TF[0] + TC[0] > 60 * 12)
                    res = minRes + getCount(C[0], TF[0] + TC[0] - 60 * 12);
                else if (TF[1] + TC[1] > 60 * 12)
                    res = minRes + getCount(C[1], TF[1] + TC[1] - 60 * 12);
                else
                    res = minRes;

                output.WriteLine("Case #{0}: {1}", testCase, res);
            }
        }

        static void Main(string[] args)
        {
            try
            {
                SolveAllTests(Console.In, Console.Out);
                /*using (TextReader input = File.OpenText("test.in"))
                {
                    using (TextWriter output = File.CreateText("B-test.out"))
                        SolveAllTests(input, output);
                }*/
            }
            catch (Exception e)
            {
                Console.Error.WriteLine("ERROR: " + e.Message);
            }
        }
    }
}
