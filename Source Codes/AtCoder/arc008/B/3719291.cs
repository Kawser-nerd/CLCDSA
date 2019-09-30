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
            int iM = int.Parse(sS[0]);
            string sN = System.Console.ReadLine().Trim();
            string sK = System.Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<string> lstName = new List<string>();
            List<string> lstKitO = new List<string>();
            for (int j = 0; j < sN.Length; j++) { lstName.Add(sN.Substring(j, 1)); }
            for (int j = 0; j < sK.Length; j++) { lstKitO.Add(sK.Substring(j, 1)); }
            List<List<string>> lstKitD = new List<List<string>>();          // ??????
            int iOut = 0;
            List<string> lstTmp = new List<string>();
            for (int j = 0; j < lstKitO.Count; j++) { lstTmp.Add(lstKitO[j]); }
            lstKitD.Add(lstTmp);
            for (int i = 0; i < lstName.Count; i++)
            {
                Boolean bEx = false;
                for (int j = 0; j < lstKitD.Count; j++)                     // ?????????
                {
                    if (lstKitD[j].Contains(lstName[i]))                    // ?????????
                    {
                        lstKitD[j].Remove(lstName[i]);                      // ???????
                        bEx = true;
                        break;
                    }
                }
                if (!bEx)                                                   // ????????????????????
                {
                    List<string> lstTm2 = new List<string>();
                    for (int j = 0; j < lstKitO.Count; j++) { lstTm2.Add(lstKitO[j]); }
                    lstKitD.Add(lstTm2);
                    if (lstKitD[lstKitD.Count - 1].Contains(lstName[i]))    // ??????????
                    {
                        lstKitD[lstKitD.Count - 1].Remove(lstName[i]);      // ???????
                    }
                    else
                    {
                        iOut = -1;
                        break;
                    }
                }
            }
            if (iOut != -1) { iOut = lstKitD.Count(); }

            // ??
            System.Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}