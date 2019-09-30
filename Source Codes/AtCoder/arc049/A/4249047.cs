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
            string[] s2 = System.Console.ReadLine().Trim().Split(' ');

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstInp = new List<int>();
            for (int i = 0; i < s2.Length; i++) { lstInp.Add(int.Parse(s2[i]) - 0); }
            lstInp.Reverse();
            List<char> cS = sS.ToList();
            for (int i = 0; i < lstInp.Count; i++)
            {
                if (lstInp[i] == cS.Count) { cS.Add('"'); }
                else { cS.Insert(lstInp[i], '"'); }
            }
            string sOut = string.Join("", cS);

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