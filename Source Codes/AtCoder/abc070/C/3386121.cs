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
            List<decimal> lstT = new List<decimal>();
            for (int i = 0; i < iN; i++)
            {
                sS = Console.ReadLine().Trim();
                lstT.Add(decimal.Parse(sS));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            decimal iOut = lstT[0];
            for (int i = 1; i < lstT.Count; i++)
            {
                iOut = Lcm(iOut, lstT[i]);
            }

            //??
            Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // ???????
        private static decimal Lcm(decimal a, decimal b)
        {
            return a * (b / Gcd(a, b));                         // ?? ??? a * b / Gcd(a, b);
        }

        // ???????
        private static decimal Gcd(decimal a, decimal b)
        {
            if (a < b) { return Gcd(b, a); }
            while (b != 0)
            {
                decimal remainder = a % b;
                a = b;
                b = remainder;
            }
            return a;
        }
}