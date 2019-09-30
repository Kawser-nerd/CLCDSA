using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            Dictionary<string, string> dicVs = new Dictionary<string, string>() { {"Left", "<"}, {"Right", ">"}, {"AtCoder", "A"}, };

            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<string> lstOut = new List<string>();
            for (int i = 0; i < sS.Length; i++) { lstOut.Add(dicVs[sS[i]]); }

            // ??
            System.Console.WriteLine("{0}", string.Join(" ", lstOut).ToString().Trim());
            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}