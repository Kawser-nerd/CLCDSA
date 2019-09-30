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

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstOut = new List<int>();
            for (int i = 1; i <= iN ; i += 2)
            {
                int iCnt = 0;
                for (int j = 1; j <= i ; j++)
                {
                    if (i % j == 0) { iCnt += 1; }
                }
                lstOut.Add(iCnt);
            }
            int iOut = lstOut.Count(x=> x == 8);

            // ??
            System.Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}