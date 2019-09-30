using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class D : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string[] s = Console.ReadLine().Split();
                int P = int.Parse(s[0]);
                long[] E = new long[P];
                long[] F = new long[P];
                s = Console.ReadLine().Split(' ');
                for (int i = 0; i < P; i++)
                {
                    E[i] = long.Parse(s[i]);
                }
                s = Console.ReadLine().Split(' ');
                for (int i = 0; i < P; i++)
                {
                    F[i] = long.Parse(s[i]);
                }
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(P, E, F)
                    );
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(int P, long[] E, long[] F)
        {
            Dictionary<long, int> idxMap = new Dictionary<long, int>();
            for (int i = 0; i < P; i++)
            {
                idxMap[E[i]] = i;
            }

            List<long> ret = new List<long>();
            int idx = 0;
            long[] usedother = new long[P];
            while (idx < P)
            {
                if (F[idx] > 0)
                {
                    long val = E[idx];
                    if (val > 0)
                    {
                        idx = CheckFactor(P, E, F, idxMap, ret, idx, usedother, val, 0, P, 1);
                    }
                    else if (val<0)
                    {
                        idx = CheckFactor(P, E, F, idxMap, ret, idx, usedother, val, P-1, -1, -1);
                    }
                    else
                    {
                        // Val==0
                        bool good=true;
                        for (int i = 0; i < P; i++)
                        {
                            if (F[i] % 2 == 1)
                            {
                                good = false;
                                break;
                            }
                        }
                        if (good)
                        {
                            for (int i = 0; i < P; i++)
                            {
                                F[i] /= 2;
                            }
                            ret.Add(0);
                        }
                        else
                        {
                            idx++;
                        }
                    }
                }
                else
                {
                    idx++;
                }
            }

            string sret = "";
            for (int i = 0; i < ret.Count; i++)
            {
                sret += ret[i].ToString();
                if (i < ret.Count - 1) sret += " ";
            }

            return sret;
        }

        private static int CheckFactor(int P, long[] E, long[] F, Dictionary<long, int> idxMap, List<long> ret, int idx, long[] usedother, long val, int startidx, int endidx, int step)
        {
            bool good = true;
            for (int i = 0; i < P; i++)
            {
                usedother[i] = 0;
            }
            for (int i = startidx; i != endidx; i+=step)
            {
                if (F[i] - usedother[i] > 0)
                {
                    long need = F[i] - usedother[i];
                    int other;
                    if (idxMap.TryGetValue(E[i] + val, out other))
                    {
                        if (F[other] >= need)
                        {
                            usedother[other] += need;
                        }
                        else
                        {
                            good = false;
                            break;
                        }
                    }
                    else
                    {

                        good = false;
                        break;
                    }
                }
            }

            if (good)
            {
                for (int i = 0; i < P; i++)
                {
                    F[i] -= usedother[i];
                }
                ret.Add(val);
            }
            else
            {
                idx++;
            }
            return idx;
        }
    }
}
