using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<List<int>> lC = new List<List<int>>();
            for (int i = 0; i < 3; i++)
            {
                string[] sS = Console.ReadLine().Trim().Split(' ');
                List<int> lstT = new List<int>();
                for (int j = 0; j < 3; j++)
                {
                    lstT.Add(int.Parse(sS[j]));
                }
                lC.Add(lstT);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "No";
            int b1 = 0, b2 = 0, b3 = 0;
            Boolean bOK = false;
            for (int a1 = 0; a1 <= lC[0][0]; a1++)
            {
                b1 = lC[0][0] - a1;
                b2 = lC[0][1] - a1;
                b3 = lC[0][2] - a1;
                for (int a2 = 0; a2 <= lC[1][0]; a2++)
                {
                    if (lC[1][0] == a2 + b1 &&
                        lC[1][1] == a2 + b2 &&
                        lC[1][2] == a2 + b3)
                    {
                        for (int a3 = 0; a3 <= lC[2][0]; a3++)
                        {
                            if (lC[2][0] == a3 + b1 &&
                                lC[2][1] == a3 + b2 &&
                                lC[2][2] == a3 + b3)
                            {
                                bOK = true;
                                break;
                            }
                        }
                    }
                    if (bOK) { break; }
                }
                if (bOK) { break; }
            }
            if (bOK) { sOut = "Yes"; }

            // ??
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