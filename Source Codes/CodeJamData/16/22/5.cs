using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class B : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string[] s = Console.ReadLine().Split();
                string C = s[0];
                string J = s[1];
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(C, J)
                    );
                tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWorkBrute(string C, string J)
        {
            int N = C.Length;
            int MAX = 1;
            for (int i = 0; i < N; i++)
            {
                MAX *= 10;
            }

            long bestC = 9999999;
            long bestJ = 0;

            for (int iC = 0; iC < MAX; iC++)
            {
                string testC = iC.ToString();
                while (testC.Length != N)
                {
                    testC = '0' + testC;
                }
                bool legalC = true;
                for (int i = 0; i < N; i++)
                {
                    if (C[i] != '?' && C[i] != testC[i]) legalC = false;
                }
                if (!legalC) continue;
                for (int iJ = 0; iJ < MAX; iJ++)
                {
                    string testJ = iJ.ToString();
                    while (testJ.Length != N)
                    {
                        testJ = '0' + testJ;
                    }
                    bool legalJ = true;
                    for (int i = 0; i < N; i++)
                    {
                        if (J[i] != '?' && J[i] != testJ[i]) legalJ = false;
                    }
                    if (!legalJ) continue;

                    Improve(ref bestC, ref bestJ, iC, iJ);
                }
            }

            string Cret = bestC.ToString();
            string Jret = bestJ.ToString();
            while (Cret.Length < N)
            {
                Cret = '0' + Cret;
            }

            while (Jret.Length < N)
            {
                Jret = '0' + Jret;
            }

            return string.Format("{0} {1}", Cret, Jret);
        }

        private string DoWork(string C, string J)
        {
            int N = C.Length;
            int bothContrainedDiffIdx = -1;

            string H = "";
            string L = "";
            bool swap = false;

            for (int i = 0; i < N; i++)
            {
                if (C[i] != '?' && J[i] != '?' && C[i] != J[i])
                {
                    bothContrainedDiffIdx = i;
                    if (C[i] > J[i])
                    {
                        H = C;
                        L = J;
                    }
                    else
                    {
                        H = J;
                        L = C;
                        swap = true;
                    }
                    break;
                }
            }

            if (bothContrainedDiffIdx == -1)
            {
                char[] res = new char[N];
                for (int i = 0; i < N; i++)
                {
                    if (C[i] != '?')
                    {
                        res[i] = C[i];
                    }
                    else if (J[i] != '?')
                    {
                        res[i] = J[i];
                    }
                    else
                    {
                        res[i] = '0';
                    }
                }

                return string.Format("{0} {1}", new string(res), new string(res));
            }

            char[] resH = new char[N];
            char[] resL = new char[N];

            // First match, then chase
            for (int i = 0; i < bothContrainedDiffIdx; i++)
            {
                if (H[i] != '?')
                {
                    resH[i] = H[i];
                    resL[i] = H[i];
                }
                else if (L[i] != '?')
                {
                    resH[i] = L[i];
                    resL[i] = L[i];
                }
                else
                {
                    resH[i] = '0';
                    resL[i] = '0';
                }
            }

            resH[bothContrainedDiffIdx] = H[bothContrainedDiffIdx];
            resL[bothContrainedDiffIdx] = L[bothContrainedDiffIdx];

            for (int i = bothContrainedDiffIdx + 1; i < N; i++)
            {
                if (H[i] != '?')
                {
                    resH[i] = H[i];
                }
                else
                {
                    resH[i] = '0';
                }

                if (L[i] != '?')
                {
                    resL[i] = L[i];
                }
                else
                {
                    resL[i] = '9';
                }
            }

            long Cbest;
            long Jbest;
            if (!swap)
            {
                Cbest = long.Parse(new string(resH));
                Jbest = long.Parse(new string(resL));
            }
            else
            {
                Jbest = long.Parse(new string(resH));
                Cbest = long.Parse(new string(resL));
            }

            // Repaint the end in prep for swap
            for (int i = bothContrainedDiffIdx + 1; i < N; i++)
            {
                if (H[i] != '?')
                {
                    resH[i] = H[i];
                }
                else
                {
                    resH[i] = '9';
                }

                if (L[i] != '?')
                {
                    resL[i] = L[i];
                }
                else
                {
                    resL[i] = '0';
                }
            }

            // Increase L by min, left of pivot
            char[] Lbackup = new char[N];
            Array.Copy(resL, Lbackup, N);

            for (int i = bothContrainedDiffIdx - 1; i >= 0; i--)
            {
                if (L[i] == '?')
                {
                    if (resL[i] != '9')
                    {
                        resL[i]++;
                        break;
                    }
                    else
                    {
                        resL[i] = '0';
                    }
                }
            }

            long Ctry;
            long Jtry;
            if (!swap)
            {
                Ctry = long.Parse(new string(resH));
                Jtry = long.Parse(new string(resL));
            }
            else
            {
                Jtry = long.Parse(new string(resH));
                Ctry = long.Parse(new string(resL));
            }

            Improve(ref Cbest, ref Jbest, Ctry, Jtry);

            Array.Copy(Lbackup, resL, N);

            // Decrease H by min, left of pivot
            for (int i = bothContrainedDiffIdx - 1; i >= 0; i--)
            {
                if (H[i] == '?')
                {
                    if (resH[i] != '0')
                    {
                        resH[i]--;
                        break;
                    }
                    else
                    {
                        resH[i] = '9';
                    }
                }
            }

            if (!swap)
            {
                Ctry = long.Parse(new string(resH));
                Jtry = long.Parse(new string(resL));
            }
            else
            {
                Jtry = long.Parse(new string(resH));
                Ctry = long.Parse(new string(resL));
            }

            Improve(ref Cbest, ref Jbest, Ctry, Jtry);

            string Cret = Cbest.ToString();
            string Jret = Jbest.ToString();
            while (Cret.Length < N)
            {
                Cret = '0' + Cret;
            }

            while (Jret.Length < N)
            {
                Jret = '0' + Jret;
            }

            return string.Format("{0} {1}", Cret, Jret);
        }

        private void Improve(ref long CBest, ref long JBest, long CTry, long JTry)
        {
            long diff = Math.Abs(CBest - JBest);
            long diffTry = Math.Abs(CTry - JTry);

            if (diff > diffTry)
            {
                CBest = CTry;
                JBest = JTry;
                return;
            }

            if (diff < diffTry)
            {
                return;
            }

            if (CBest > CTry)
            {
                CBest = CTry;
                JBest = JTry;
                return;
            }

            if (CBest < CTry)
            {
                return;
            }

            if (JBest > JTry)
            {
                CBest = CTry;
                JBest = JTry;
                return;
            }

            return;
        }
    }
}
