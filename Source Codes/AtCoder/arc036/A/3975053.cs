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
            int iK = int.Parse(sS[1]);
            List<int> lstInp = new List<int>();
            for (int i = 0; i < iN; i++) { lstInp.Add(int.Parse(System.Console.ReadLine().Trim())); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = -1;
            for (int i = 0; i < lstInp.Count - 2; i++)
            {
                int iSp = lstInp[i] + lstInp[i + 1] + lstInp[i + 2];
                if (iSp < iK) { iOut = i + 3; break; }
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