using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<ClsPra> lstPra = new List<ClsPra>()
            { { new ClsPra() { sChr = "b", sFig = "1" } }, { new ClsPra() { sChr = "c", sFig = "1" } },
              { new ClsPra() { sChr = "d", sFig = "2" } }, { new ClsPra() { sChr = "w", sFig = "2" } },
              { new ClsPra() { sChr = "t", sFig = "3" } }, { new ClsPra() { sChr = "j", sFig = "3" } },
              { new ClsPra() { sChr = "f", sFig = "4" } }, { new ClsPra() { sChr = "q", sFig = "4" } },
              { new ClsPra() { sChr = "l", sFig = "5" } }, { new ClsPra() { sChr = "v", sFig = "5" } },
              { new ClsPra() { sChr = "s", sFig = "6" } }, { new ClsPra() { sChr = "x", sFig = "6" } },
              { new ClsPra() { sChr = "p", sFig = "7" } }, { new ClsPra() { sChr = "m", sFig = "7" } },
              { new ClsPra() { sChr = "h", sFig = "8" } }, { new ClsPra() { sChr = "k", sFig = "8" } },
              { new ClsPra() { sChr = "n", sFig = "9" } }, { new ClsPra() { sChr = "g", sFig = "9" } },
              { new ClsPra() { sChr = "z", sFig = "0" } }, { new ClsPra() { sChr = "r", sFig = "0" } },
              { new ClsPra() { sChr = "a", sFig = ""  } }, { new ClsPra() { sChr = "e", sFig = ""  } },
              { new ClsPra() { sChr = "i", sFig = ""  } }, { new ClsPra() { sChr = "o", sFig = ""  } },
              { new ClsPra() { sChr = "u", sFig = ""  } }, { new ClsPra() { sChr = "y", sFig = ""  } },
              { new ClsPra() { sChr = ".", sFig = ""  } }, { new ClsPra() { sChr = ",", sFig = ""  } },
            };

            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            sS = System.Console.ReadLine().Trim().Split(' ');
            List<string> lstWod = new List<string>();
            for (int i = 0; i < sS.Length; i++) { lstWod.Add(sS[i]); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<string> lstRet = new List<string>();
            for (int i = 0; i < lstWod.Count; i++)
            {
                string sOne = lstWod[i].ToLower();                              // ????????
                for (int j = 0; j < lstPra.Count; j++)
                {
                    sOne = sOne.Replace(lstPra[j].sChr, lstPra[j].sFig);        // ?????or?????
                }
                if (sOne != "") { lstRet.Add(sOne); }                           // ???????
            }
            
            // ??
            System.Console.WriteLine("{0}", string.Join(" ", lstRet.ToArray()).ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // ?????
        private class ClsPra
        {
            public string sChr { get; set; } = "";      // ??
            public string sFig { get; set; } = "";      // ??
        }

}