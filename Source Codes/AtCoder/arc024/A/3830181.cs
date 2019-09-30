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
            int iL = int.Parse(sS[0]);
            int iR = int.Parse(sS[1]);
            List<int> lstL = new List<int>();
            List<int> lstR = new List<int>();
            sS = System.Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < sS.Length; j++) { lstL.Add(int.Parse(sS[j])); }
            sS = System.Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < sS.Length; j++) { lstR.Add(int.Parse(sS[j])); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            for (int i = lstL.Count - 1; i >= 0; i--)
            {
                for (int j = lstR.Count - 1; j >= 0; j--)
                {
                    if (lstL[i] == lstR[j]) { iOut += 1; lstL.RemoveAt(i); lstR.RemoveAt(j); break; }
                }
            }

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