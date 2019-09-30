using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            sS = Console.ReadLine().Trim().Split(' ');
            int iD = int.Parse(sS[0]);
            int iX = int.Parse(sS[1]);
            List<int> lstA = new List<int>();
            for (int i = 0; i < iN; i++) { lstA.Add(int.Parse(Console.ReadLine().Trim())); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = iX;
            for (int i = 0; i < lstA.Count; i++)
            {
                int j = 0;
                while (true)
                {
                    if (j * lstA[i] + 1 > iD) { break; }
                    iOut += 1;
                    j += 1;
                }
            }

            // ??
            Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}