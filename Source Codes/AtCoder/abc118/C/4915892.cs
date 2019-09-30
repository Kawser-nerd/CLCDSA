using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            sS = System.Console.ReadLine().Trim().Split(' ');
            List<int> lstM = new List<int>();
            for (int i = 0; i < sS.Length; i++)
            {
                lstM.Add(int.Parse(sS[i]));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstM.Sort();
            int iGcd = lstM[0];
            for (int i = 1; i < lstM.Count; i++)
            {
                iGcd = Gcd(iGcd, lstM[i]);
            }

            // ??
            System.Console.WriteLine("{0}", iGcd.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // ???????
        private static int Lcm(int a, int b)
        {
            return a * b / Gcd(a, b);
        }

        // ???????
        private static int Gcd(int a, int b)
        {
            if (a < b) { return Gcd(b, a); }
            while (b != 0)
            {
                var remainder = a % b;
                a = b;
                b = remainder;
            }
            return a;
        }

}