using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            int iN = int.Parse(Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iK = (int)Math.Sqrt(iN);
            List<int> lstSum = new List<int>();
            for (int i = 1; i <= iK; i++)
            {
                int iTate = i;
                int iYoko = iN / i;
                int iDeff = 0;
                int iAmar = 0;
                iAmar = iN - iTate * iYoko;
                iDeff = Math.Abs(iYoko - iTate);
                lstSum.Add(iAmar + iDeff);
            }
            lstSum.Sort();

            // ??
            Console.WriteLine("{0}", lstSum[0].ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}