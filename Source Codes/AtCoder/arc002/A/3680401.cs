using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string s2 = System.Console.ReadLine().Trim();
            int iY = int.Parse(s2);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "NO";
            if (iY % 4 == 0)
            {
                sOut = "YES";
                if (iY % 100 == 0)
                {
                    sOut = "NO";
                    if (iY % 400 == 0)
                    {
                        sOut = "YES";
                    }
                }
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