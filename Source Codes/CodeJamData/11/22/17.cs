using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class HotDogs : GCJBase
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
                int C = int.Parse(s.Split(' ')[0]);
                int D = int.Parse(s.Split(' ')[1]);
                List<int> vendors = new List<int>();
                for (int i = 0; i < C; i++)
                {
                    s = Console.ReadLine();
                    string P = s.Split(' ')[0];
                    int p;
                    if (P[0] == '|')
                    {
                        p = -int.Parse(P.Trim(new char[] { '|' }));
                    }
                    else
                    {
                        p = int.Parse(P);
                    }
                    int V = int.Parse(s.Split(' ')[1]);
                    for (int j = 0; j < V; j++)
                    {
                        vendors.Add(p);
                    }
                }
                double ret = VendorMove(vendors, D);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private double VendorMove(List<int> vendors, int D)
        {
            double ret = 0;
            vendors.Sort();
            for (int i = 0; i < vendors.Count; i++)
            {
                for (int j = i+1; j < vendors.Count; j++)
                {
                    int v = j - i + 1;
                    double dis = vendors[j] - vendors[i];
                    double spreadneeded = (v-1)*D;
                    if (dis < spreadneeded)
                    {
                        double walkneeded = (spreadneeded - dis) / 2;
                        ret = Math.Max(ret, walkneeded);
                    }
                }
            }

            return ret;
            //D *= 2;
            //int min = vendors[0] - vendors.Count*D;
            //int max = vendors[0] + vendors.Count*D;

            //// cheapest way of putting out v vendors with everyone to the left of or equal to p
            //int[,] bestmin = new int[vendors.Count + 1, max-min+1];

            //for (int i = min; i <= max; i++)
            //{
            //    bestmin[0, i - min] = 0;
            //    for (int v = 0; v < vendors.Count; v++)
            //    {
            //        bestmin[v + 1, i - min] = 99999;
            //    }
            //}

            //for (int v = 0; v < vendors.Count; v++)
            //{
            //    for (int p = min; p <=max; p++)
            //    {
            //        int cheapest = 99999;
            //        int thisdis = Math.Abs(vendors[v]-p);
            //        for (int pp = min; pp+D <= p; pp++)
            //        {
            //            if (cheapest<=thisdis) break;
            //            cheapest = Math.Min(cheapest, bestmin[v, pp - min]);
            //        }
            //        bestmin[v + 1, p-min] = Math.Max(cheapest, thisdis);
            //    }
            //}

            //int ret = 99999;
            //for (int i = min; i <=max; i++)
            //{
            //    ret = Math.Min(ret, bestmin[vendors.Count, i - min]);
            //}
            //return ret;
        }

    }
}
