using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            Dictionary<string, string> dicWek= new Dictionary<string, string>()
            { { "Sunday",    "0" },
              { "Monday",    "5" },
              { "Tuesday",   "4" },
              { "Wednesday", "3" },
              { "Thursday",  "2" },
              { "Friday",    "1" },
              { "Saturday",  "0" },
            };

            // ??
            string sS = System.Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            // ??
            System.Console.WriteLine("{0}", dicWek[sS].ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}