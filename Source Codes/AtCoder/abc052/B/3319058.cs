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
            int iN = int.Parse(sS);
            sS = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iX = 0;
            List<int> lstRst = new List<int>();
            lstRst.Add(iX);
            for (int i = 0; i < sS.Length; i++)
            {
                string sD = sS.Substring(i, 1);
                if (sD == "I") { iX += 1; }
                else { iX -= 1; }
                lstRst.Add(iX);
            }
            
            //??
            Console.WriteLine("{0}", lstRst.Max().ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}