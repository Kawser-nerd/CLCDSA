using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class ProperShuffle : GCJBase
    {
        Random random = new Random();
        private void DoStuff()
        {
            int N = 1000;
            int[] perm = new int[N];
            char[] c = new char[N];
            int[] sCount = new int[1000];
            Dictionary<string, int> dic = new Dictionary<string,int>();
            int[,] trans = new int[N, N];
            int A = 10000;
            int correct = 0;
            int falsegood = 0;
            int falsebad = 0;
            double goodscore = 0;
            double badscore = 0;
            int goodcount = 0;
            int badcount = 0;
            for (int a = 0; a < A; a++)
            {
                for (int i = 0; i < N; i++)
                {
                    perm[i] = i;
                }
                bool good = random.Next(2) == 0;
                if (good)
                {
                    goodcount++;
                    GoodShuffle(perm);
                }
                else
                {
                    badcount++;
                    BadShuffle(perm);
                }
                for (int i = 0; i < N; i++)
                {
                    //c[i] = (char)('0' + perm[i]);
                    trans[perm[i], i]++;
                }
                double score = 0;
                int shiftCount = ShuffleCheck(perm, ref score);
                if (good)
                {
                    goodscore += score;
                }
                else
                {
                    badscore += score;
                }

                //if (shiftCount > 203)
                if (score>0.684)
                {
                    // Choose bad

                    if (good)
                    {
                        falsebad++;
                    }
                    else
                    {
                        correct++;
                    }
                }
                else
                {
                    // Choose good
                    if (good)
                    {
                        correct++;
                    }
                    else
                    {
                        falsegood++;
                    }
                }
                //sCount[shiftCount]++;
                //string s = new string(c);
                //if (!dic.ContainsKey(s)) dic[s] = 0;
                //dic[s]++;
            }

            double acc = 1.0 * correct / A;
            goodscore /= goodcount;
            badscore /= badcount;

            int[] shiftAcc = new int[1000];
            for (int i = 1; i < 1000; i++)
            {
                shiftAcc[i] = shiftAcc[i - 1] + sCount[i];
            }
        }

        private int ShuffleCheck(int[] perm, ref double score)
        {
            score = 0;
            int N = perm.Length;
            int shiftcount = 0;

            for (int i = 0; i < N-250; i++)
            {
                if (perm[i] > i && perm[i] <= i + 250)
                {
                    shiftcount++;
                }
            }

            for (int i = 0; i < N-1; i++)
            {
                if (perm[i] > i && perm[i] <= i + 200)
                {
                    score += 1.0 / (200 + perm[i] - i);
                }
                if (perm[i] == i) score -= 1.0 / 100;
            }

            // Expect 90

            return shiftcount;
        }

        private void BadShuffle(int[] perm)
        {
            int N = perm.Length;
            for (int i = 0; i < N; i++)
            {
                int r = random.Next(0, N);
                int tmp = perm[r];
                perm[r] = perm[i];
                perm[i] = tmp;
            }
        }

        private void GoodShuffle(int[] perm)
        {
            int N = perm.Length;
            for (int i = 0; i < N; i++)
            {
                int r = random.Next(i, N);
                int tmp = perm[r];
                perm[r] = perm[i];
                perm[i] = tmp;
            }
        }

        public override void Solve()
        {
            //DoStuff();
            //return;



            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                int N = int.Parse(s);
                string[] sPerm = Console.ReadLine().Split(' ');
                int[] perm = new int[N];
                for (int i = 0; i < N; i++)
                {
                    perm[i] = int.Parse(sPerm[i]);
                }
                string ret = guessGen(perm);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string guessGen(int[] perm)
        {
            double score = 0;
            int aslkdjf = ShuffleCheck(perm, ref score);
            if (score > 0.684) return "BAD";
            return "GOOD";
        }

    }
}
