using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            List<ClsPos> lstInp = new List<ClsPos>();
            for (int i = 0; i < iN; i++)
            {
                sS = System.Console.ReadLine().Trim().Split(' ');
                lstInp.Add(new ClsPos() { iX = double.Parse(sS[0]), iY = double.Parse(sS[1]) });
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<double> lstDif = new List<double>();
            for (int i = 0; i < lstInp.Count; i++)
            {
                for (int j = i + 1; j < lstInp.Count; j++)
                {
                    lstDif.Add(Math.Sqrt(Math.Pow(lstInp[i].iX - lstInp[j].iX, 2) + Math.Pow(lstInp[i].iY - lstInp[j].iY, 2)));
                }
            }
            lstDif.Sort(delegate (double mca1, double mca2) { return (int)(mca2 * 10000 - mca1 * 10000); });     // ??

            // ??
            System.Console.WriteLine("{0}", lstDif[0].ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        private class ClsPos
        {
            public double iX { get; set; } = 0;
            public double iY { get; set; } = 0;
        }

}