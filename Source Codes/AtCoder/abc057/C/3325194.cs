using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            long lN = long.Parse(Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            long lSq = (long)Math.Sqrt(lN);
            List<int> lstSmp = new List<int>();
            for (long i = 1; i <= lSq; i++)
            {
                if (lN % i == 0)
                {
                    int iA = i.ToString().Length;                       // A???
                    int iB = ((long)(lN / i)).ToString().Length;        // B???
                    if (iA >= iB) { lstSmp.Add(iA); }                   // ???????
                    else { lstSmp.Add(iB); }
                }
            }
            if (lstSmp.Count > 1) { lstSmp.Sort(); }                    // ??????

            //??
            Console.WriteLine("{0}", lstSmp[0].ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}