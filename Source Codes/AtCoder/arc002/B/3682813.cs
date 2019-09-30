using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            DateTime dNow = DateTime.Parse(System.Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            while (true)
            {
                string[] sS = dNow.ToString("yyyy/MM/dd").Split('/');
                double iY = double.Parse(sS[0]);
                double iM = double.Parse(sS[1]);
                double iD = double.Parse(sS[2]);
                if ((double)(iY / iM / iD) % 1 == 0) { break;  }
                dNow = dNow.AddDays(1);
            }

            // ??
            System.Console.WriteLine("{0}", dNow.ToString("yyyy/MM/dd").Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}