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
            int iM = int.Parse(sS[1]);
            List<int> lstM = new List<int>();
            for (int i = 0; i <= iM; i++) { lstM.Add(0); }
            for (int i = 0; i < iN; i++)
            {
                sS = System.Console.ReadLine().Trim().Split(' ');
                for (int j = 1; j < sS.Length; j++)
                {
                    lstM[int.Parse(sS[j])] += 1;
                }
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = lstM.Count(value => value == iN);

            // ??
            System.Console.WriteLine("{0}", iOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}