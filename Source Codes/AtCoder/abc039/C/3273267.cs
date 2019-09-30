using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            Dictionary<string, string> DicCmp = new Dictionary<string, string>()
            { {"WBWBWWBWBWBWWBWBWWBW", "Do"},
              {"WBWWBWBWBWWBWBWWBWBW", "Re"},
              {"WWBWBWBWWBWBWWBWBWBW", "Mi"},
              {"WBWBWBWWBWBWWBWBWBWW", "Fa"},
              {"WBWBWWBWBWWBWBWBWWBW", "So"},
              {"WBWWBWBWWBWBWBWWBWBW", "La"},
              {"WWBWBWWBWBWBWWBWBWWB", "Si"}, };

            // ??
            Console.WriteLine("{0}", DicCmp[sS].ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}