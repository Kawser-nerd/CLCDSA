using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class C : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                int N = int.Parse(s);
                string[] sentences = new string[N];
                for (int i = 0; i < N; i++)
                {
                    sentences[i] = Console.ReadLine();
                }
                long ret = minShared(N,sentences);

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

        private int minShared(int N, string[] sentences)
        {
            Dictionary<string, int> wordMap = new Dictionary<string, int>();
            int[][] wordIdx = new int[N][];
            int newidx = 0;

            for (int i = 0; i < N; i++)
            {
                string[] words = sentences[i].Split(' ');
                wordIdx[i] = new int[words.Length];
                for (int j = 0; j < words.Length; j++)
                {
                    int idx;
                    if (!wordMap.ContainsKey(words[j]))
                    {
                        idx = newidx++;
                        wordMap[words[j]] = idx;
                    }
                    else
                    {
                        idx = wordMap[words[j]];
                    }
                    wordIdx[i][j] = idx;
                }
            }
            string[][] senWords = new string[N][];
            for (int i = 0; i < N; i++)
            {
                senWords[i] = sentences[i].Split(' ');
            }
            int ret = int.MaxValue;
            for (int a = 0; a < 1<<(N-2); a++)
            {
                int[] lang = new int[newidx];
                for (int i = 0; i < N; i++)
                {
                    int thislang = 1;
                    if (i == 1) thislang=2;
                    if (i > 1 && ((a & (1 << (i - 2))) > 0))
                    {
                        thislang = 2;
                    }

                    for (int j = 0; j < wordIdx[i].Length; j++)
                    {
                        lang[wordIdx[i][j]] |= thislang;
                    }
                }
                int tot = 0;
                for (int i = 0; i < newidx; i++)
                {
                    if (lang[i] == 3) tot++;
                }
                ret = Math.Min(ret, tot);
            }

            return ret;
        }

    }
}
