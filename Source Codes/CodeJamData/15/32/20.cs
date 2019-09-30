using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            B();
        }

        static void B()
        {
            StreamReader sr = new StreamReader("C:\\CodeJam\\Round1C\\B-small-attempt1.in");
            StreamWriter sw = new StreamWriter("C:\\CodeJam\\Round1C\\B-small-attempt1.out");
            int T, K, L, S;

            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] toks = sr.ReadLine().Split(' ');
                K = int.Parse(toks[0]);
                L = int.Parse(toks[1]);
                S = int.Parse(toks[2]);


                string KString = sr.ReadLine();
                string LString = sr.ReadLine();

                int subLen = LString.Length;
                for (int k = 1; k < LString.Length; k++)
                {
                    if (LString.IndexOf(LString.Substring(k)) == 0)
                    {
                        subLen = k;
                        break;
                    }
                }

                int len = LString.Length - subLen;
                int totReq = (S - len) / subLen;

                double prob = 1+(S-L);
                for (int j = 0; j < L; j++)
                {
                    int occurence = 0;
                    for (int k = 0; k < K; k++)
                    {
                        if (LString[j] == KString[k])
                            occurence++;
                    }
                    prob = prob * occurence;
                    prob = prob / K;
                    if (occurence == 0)
                        totReq = 0;
                }
                prob = totReq - prob;

                sw.WriteLine(String.Format("Case #{0}: {1}", (i + 1).ToString(), prob.ToString()));
            }

            sr.Close();
            sw.Close();
        }
    }
}
