using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] s2 = System.Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(s2[0]);
            int iM = int.Parse(s2[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            for (int i = 1; i <= iN; i++)
            {
                if (i != iM) { iOut = i; break; }
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