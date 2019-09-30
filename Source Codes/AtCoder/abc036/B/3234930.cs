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
            List<List<string>> lstBrd = new List<List<string>>();
            List<List<string>> lstOut = new List<List<string>>();
            for (int i = 0; i < iN; i++)
            {
                string sS = Console.ReadLine().Trim();
                List<string> lstRow = new List<string>();
                List<string> lstRo2 = new List<string>();
                for (int j = 0; j < iN; j++)
                {
                    lstRow.Add(sS.Substring(j, 1));
                    lstRo2.Add("");
                }
                lstBrd.Add(lstRow);
                lstOut.Add(lstRo2);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            for (int i = 0; i < lstOut.Count; i++)              // ?
            {
                for (int j = 0; j < lstOut[i].Count; j++)       // ?
                {
                    lstOut[i][j] = lstBrd[lstBrd.Count - 1 - j][i];
                }
            }

            // ??
            for (int i = 0; i < lstOut.Count; i++)              // ?
            {
                string sOut = "";
                for (int j = 0; j < lstOut[i].Count; j++)       // ?
                {
                    sOut += lstOut[i][j];
                }
                Console.WriteLine("{0}", sOut.ToString());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}