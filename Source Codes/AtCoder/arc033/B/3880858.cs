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
            int iA = int.Parse(sS[0]);
            int iB = int.Parse(sS[1]);
            string[] sA = System.Console.ReadLine().Trim().Split(' ');
            string[] sB = System.Console.ReadLine().Trim().Split(' ');
            //// ??
            //int iA = 100000;
            //int iB = 100000;
            //List<string> lA = new List<string>();
            //List<string> lB = new List<string>();
            //for (int i = 0; i < iA; i++) { lA.Add(i.ToString()); }
            //for (int i = 0; i < iB; i++) { lB.Add((i+90000).ToString()); }
            //string[] sA = lA.ToArray();
            //string[] sB = lB.ToArray();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string[] sD = sA.Intersect(sB).ToArray();
            List<string> lT = sA.ToList();
            lT.AddRange(sB.ToList());
            lT = lT.Distinct().ToList();
            double dOut = (double)sD.Length / (double)lT.Count();

            // ??
            System.Console.WriteLine("{0}", dOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}