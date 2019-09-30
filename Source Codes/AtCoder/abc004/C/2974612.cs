using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ?? N 1?30??
            List<List<int>> lstS = new List<List<int>>();
            for (int j = 0; j < 31; j++)
            {
                List<int> lstC = new List<int>() { 1, 2, 3, 4, 5, 6, };
                for (int i = 0; i < j; i++)
                {
                    int iLeft = (i % 5) + 0;
                    int iRigt = (i % 5) + 1;
                    int iTemp = lstC[iLeft];
                    lstC[iLeft] = lstC[iRigt];
                    lstC[iRigt] = iTemp;
                }
                lstS.Add(lstC);
            }

            // ??
            int iN = int.Parse(Console.ReadLine().Trim());

            // ??
            iN = iN % 30;

            //??
            string sOut = "";
            for (int i = 0; i < lstS[iN].Count; i++)
            {
                sOut += lstS[iN][i];
            }
            Console.WriteLine("{0}", sOut.Trim());


#if DEBUG
        Console.WriteLine("?????????????????????");
        Console.ReadKey();
#endif

    }

}