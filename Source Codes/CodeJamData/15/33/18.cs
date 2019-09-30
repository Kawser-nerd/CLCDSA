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
            C();
        }

        static void C()
        {
            StreamReader sr = new StreamReader("C:\\CodeJam\\Round1C\\C-small.in");
            StreamWriter sw = new StreamWriter("C:\\CodeJam\\Round1C\\C-small.out");
            int T,C,D,V;

            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] toks = sr.ReadLine().Split(' ');
                C = int.Parse(toks[0]);
                D = int.Parse(toks[1]);
                V = int.Parse(toks[2]);

                toks = sr.ReadLine().Split(' ');
                int[] DVal = new int[D];

                for (int j = 0; j < D; j++)
                {
                    DVal[j] = int.Parse(toks[j]);
                }

                int y = 0;
                int accumilated = 0;

                int dP = 0;
                while (accumilated < V)
                {
                    if (dP<DVal.Length && (DVal[dP] > (accumilated * C) + 1))//we need to issue it;
                    {
                        y++;
                        accumilated = accumilated + (accumilated * C) + 1;
                    }
                    else
                    {
                        accumilated = accumilated + DVal[dP];

                        dP++;
                    }
                }

                sw.WriteLine(String.Format("Case #{0}: {1}", (i + 1).ToString(), y.ToString()));
            }

            sr.Close();
            sw.Close();
        }
    }
}
