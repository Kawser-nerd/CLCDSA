using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<ClsFig> lstFig = new List<ClsFig>()
            { new ClsFig() { sS = "O",    sD = "0" },
              new ClsFig() { sS = "D",    sD = "0" },
              new ClsFig() { sS = "I",    sD = "1" },
              new ClsFig() { sS = "Z",    sD = "2" },
              new ClsFig() { sS = "S",    sD = "5" },
              new ClsFig() { sS = "B",    sD = "8" },
            };

            // ??
            string s2 = System.Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            for (int i = 0; i < lstFig.Count; i++) { s2 = s2.Replace(lstFig[i].sS, lstFig[i].sD); }

            // ??
            System.Console.WriteLine("{0}", s2.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // Fig
        private class ClsFig
        {
            public string sS { get; set; } = "";
            public string sD { get; set; } = "";
        }

}