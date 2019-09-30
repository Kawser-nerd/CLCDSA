using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            int iN = int.Parse(Console.ReadLine().Trim());

            // ??
            List<Decimal> lstA = new List<Decimal>();
            lstA.Add(0M); lstA.Add(0M); lstA.Add(0L); lstA.Add(1M);
            if (iN > 3)
            {
                for (int i = 4; i <= iN; i++)
                {
                    lstA.Add((lstA[i - 3] + lstA[i - 2] + lstA[i - 1]) % 10007M);
                    //lstA.Add(lstA[i - 3] + lstA[i - 2] + lstA[i - 1]) ;
                }
            }

            //??
            Console.WriteLine("{0}", lstA[iN].ToString());

#if DEBUG
            //for (int i = 1; i <= iN; i++)
            //{
            //    Console.WriteLine("{0}", lstA[i].ToString());
            //}
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

}