using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Aerobics : GCJBase
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
                int N = int.Parse(s.Split(' ')[0]);
                int W = int.Parse(s.Split(' ')[1]);
                int L = int.Parse(s.Split(' ')[2]);
                string[] rs = Console.ReadLine().Split(' ');
                int[] r = new int[N];
                for (int i = 0; i < N; i++)
                {
                    r[i] = int.Parse(rs[i]);
                }
                string ret = packing(N,r,W,L);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string packing(int N, int[] r, int W, int L)
        {
            int step = L / 10000;
            if (step < 1) step = 1;

            int[] packorder = new int[N];
            for (int i = 0; i < N; i++)
            {
                packorder[i] = i;
            }
            int[] rsort = new int[N];
            Array.Copy(r, rsort, N);
            Array.Sort(rsort, packorder);
            Array.Reverse(packorder);

            int[] xpos = new int[N];
            int[] ypos = new int[N];
            for (int i = 0; i < N; i++)
            {
                int y = 0;
                int thisr = r[packorder[i]];
                do
                {
                    int minx = 0;
                    int maxx = W;
                    for (int j = 0; j < i; j++)
                    {
                        int thaty = ypos[packorder[j]];
                        int thatx = xpos[packorder[j]];
                        int thatr = r[packorder[j]];
                        if (Math.Abs(thaty - y) < thisr + thatr)
                        {
                            minx = Math.Max(minx, thatx + thisr + thatr);
                            maxx = Math.Min(maxx, thatx - thisr - thatr);
                        }
                    }

                    if (minx <= W)
                    {
                        xpos[packorder[i]] = minx;
                        ypos[packorder[i]] = y;
                        break;
                    }
                    else if (maxx >= 0)
                    {
                        xpos[packorder[i]] = maxx;
                        ypos[packorder[i]] = y;
                        break;
                    }
                    else
                    {
                        y += step;
                    }
                    if (y > L)
                    {
                        return "Oops";
                    }
                } while (true);
            }
            string ret = "";
            for (int i = 0; i < N; i++)
            {
                ret += string.Format("{0} {1} ",xpos[i],ypos[i]);
            }
            return ret;
        }
    }
}
