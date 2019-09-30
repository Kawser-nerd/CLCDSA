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
            int iH = int.Parse(sS[0]);
            int iW = int.Parse(sS[1]);
            List<List<int>> lstA = new List<List<int>>();
            for (int i = 0; i < iH; i++)
            {
                sS = System.Console.ReadLine().Trim().Split(' ');
                List<int> lstR = new List<int>();
                for (int j = 0; j < iW; j++)
                {
                    lstR.Add(int.Parse(sS[j]));
                }
                lstA.Add(lstR);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iWm = lstA[0].Count - 1;
            List<string> lstO = new List<string>();                     // ????
            for (int i = 0; i < lstA.Count; i++)
            {
                if (i % 2 == 0)                                         // ????
                {
                    for (int j = 0; j <= iWm - 1; j++)                  // ???? ????????
                    {
                        if (lstA[i][j] % 2 == 1) { lstA[i][j] -= 1; lstA[i][j + 1] += 1; lstO.Add((i + 1).ToString() + " " + (j + 1).ToString() + " " + (i + 1).ToString() + " " + (j + 2).ToString()); }
                    }
                    if (i + 1 < lstA.Count && lstA[i][iWm] % 2 == 1) { lstA[i][iWm] -= 1; lstA[i + 1][iWm] += 1; lstO.Add((i + 1).ToString() + " " + (iWm + 1).ToString() + " " + (i + 2).ToString() + " " + (iWm + 1).ToString()); }   // ?????
                }
                else                                                    // ????
                {
                    for (int j = iWm; j > 0 ; j--)                      // ???? ????????
                    {

                        if (lstA[i][j] % 2 == 1) { lstA[i][j] -= 1; lstA[i][j - 1] += 1; lstO.Add((i + 1).ToString() + " " + (j + 1).ToString() + " " + (i + 1).ToString() + " " + (j - 1 + 1).ToString()); }
                    }
                    if (i + 1 < lstA.Count && lstA[i][0] % 2 == 1) { lstA[i][0] -= 1; lstA[i + 1][0] += 1; lstO.Add((i + 1).ToString() + " " + (0 + 1).ToString() + " " + (i + 2).ToString() + " " + (0 + 1).ToString()); }         // ?????
                }
            }

            // ??
            System.Console.WriteLine("{0}", lstO.Count.ToString().Trim());
            for (int i = 0; i < lstO.Count; i++)
            {
                System.Console.WriteLine("{0}", lstO[i].ToString().Trim());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}