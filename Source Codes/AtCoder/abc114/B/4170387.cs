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
            List<int> lstDeif = new List<int>();
            for (int i = 0; i < sS.Length - 2; i++)
            {
                lstDeif.Add(Math.Abs(753 - int.Parse(sS.Substring(i, 3))));
            }
            lstDeif.Sort();

            // ??
            System.Console.WriteLine("{0}", lstDeif[0].ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}