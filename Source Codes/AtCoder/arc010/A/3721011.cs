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
            int iA = int.Parse(sS[2]);
            int iB = int.Parse(sS[3]);
            List<int> lstDis = new List<int>();
            for (int i = 0; i < iM; i++) { lstDis.Add(int.Parse(Console.ReadLine())); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "complete";
            for (int i = 0; i < lstDis.Count; i++)
            {
                if (iN <= iA) { iN += iB; }
                iN -= lstDis[i];
                if (iN < 0) { sOut = (i + 1).ToString(); break; }
            }

            // ??
            System.Console.WriteLine("{0}", sOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}