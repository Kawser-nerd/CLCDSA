using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            int iM = int.Parse(sS[1]);
            List<string> lstN = new List<string>();
            List<string> lstM = new List<string>();
            for (int i = 0; i < iN; i++) { lstN.Add(Console.ReadLine().Trim()); }
            for (int i = 0; i < iM; i++) { lstM.Add(Console.ReadLine().Trim()); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "No";
            for (int i = 0; i <= lstN.Count - lstM.Count; i++)
            {
                int iNx = 0;                                        // ??????
                while (true)
                {
                    if (iNx > iN - iM) { break; }                   // N?????????????? N????
                    int iFx = lstN[i].IndexOf(lstM[0], iNx);        // N??????M?1?????
                    Boolean bOK = false;
                    if (iFx >= 0)                                    // N??????M?1???????
                    {
                        bOK = true;
                        for (int j = 1; j < lstM.Count; j++)        // ???M????????
                        {
                            if (lstN[i + j].Substring(iFx, iM) != lstM[j]) { bOK = false; break; }  // ????????????????? ?????????M?1?????????
                        }
                        iNx = iFx + 1;
                    }
                    else
                    {
                        break;                                      // N?????M?1??????????N????
                    }
                    if (bOK) { sOut = "Yes"; break; }
                }
                if (sOut == "Yes") {  break; }
            }

            //??
            Console.WriteLine("{0}", sOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}