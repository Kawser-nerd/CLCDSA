using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<List<string>> lstBan = new List<List<string>>();
            for (int i = 0; i < 4; i++)
            {
                string[] sS = System.Console.ReadLine().Trim().Split(' ');
                List<string> lstRow = new List<string>();
                for (int j = 0; j < 4; j++) { lstRow.Add(sS[j]); }
                lstBan.Add(lstRow);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "GAMEOVER";
            for (int i = 0; i < lstBan.Count; i++)
            {
                for (int j = 0; j < lstBan[i].Count - 1; j++)
                {
                    if (lstBan[i][j] == lstBan[i][j + 1]) { sOut = "CONTINUE"; break; }
                }
                if (sOut == "CONTINUE") { break; }
            }
            if (sOut == "GAMEOVER")
            {
                for (int j = 0; j < lstBan[0].Count; j++)
                {
                    for (int i = 0; i < lstBan.Count - 1; i++)
                    {
                        if (lstBan[i][j] == lstBan[i + 1][j]) { sOut = "CONTINUE"; break; }
                    }
                    if (sOut == "CONTINUE") { break; }
                }
            }

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