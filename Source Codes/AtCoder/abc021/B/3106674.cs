using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sInp[0]);
            sInp = Console.ReadLine().Trim().Split(' ');
            int ia = int.Parse(sInp[0]);
            int ib = int.Parse(sInp[1]);
            sInp = Console.ReadLine().Trim().Split(' ');
            int iK = int.Parse(sInp[0]);
            List<int> lstSmp = new List<int>();
            sInp = Console.ReadLine().Trim().Split(' ');
            for (int i = 0; i < sInp.Length; i++) { lstSmp.Add(int.Parse(sInp[i])); }
            
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstSmp.Sort();
            string sOut = "YES";
            if (sOut == "YES" && lstSmp.Contains(ia)) { sOut = "NO"; }
            if (sOut == "YES" && lstSmp.Contains(ib)) { sOut = "NO"; }
            if (sOut == "YES")
            {
                if (lstSmp.Count >= 2)
                {
                    for (int i = 0; i < lstSmp.Count - 1; i++)
                    {
                        if (lstSmp[i] == lstSmp[i + 1]) { sOut = "NO"; break; }
                    }
                }
            }

            // ??
            Console.WriteLine("{0}", sOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}