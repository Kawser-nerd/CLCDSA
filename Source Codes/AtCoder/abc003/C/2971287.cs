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
            int iK = int.Parse(sInp[1]);
            sInp = Console.ReadLine().Trim().Split(' ');
            List<decimal> lstR = new List<decimal>();
            for (int i = 0; i < sInp.Length; i++)
            { lstR.Add(decimal.Parse(sInp[i])); }

            // ??
            lstR.Sort();  // ??
            decimal dOut = 0M;
            for (int i = lstR.Count - iK; i < lstR.Count; i++)
            {
                dOut = (dOut + lstR[i]) / 2;
            }

            //??
            Console.WriteLine("{0}", dOut.ToString());

#if DEBUG
        Console.WriteLine("?????????????????????");
        Console.ReadKey();
#endif

    }

}