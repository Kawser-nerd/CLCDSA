using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = System.Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sR = new String(sS.Reverse().ToArray());             // ??
            string sOut = "YES";
            for (int i = 0; i < sS.Length; i++)
            {
                if (sS[i] == sR[i]) { }
                else if (sS[i] == '*' || sR[i] == '*') { }
                else { sOut = "NO"; break; }
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