using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class MagicTrick : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                int[,] board1 = new int[4, 4];
                int[,] board2 = new int[4, 4];
                int guess1;
                int guess2;
                string s = Console.ReadLine();
                guess1 = int.Parse(s);
                for (int i = 0; i < 4; i++)
                {
                    s = Console.ReadLine();
                    for (int j = 0; j < 4; j++)
                    {
                        board1[i, j] = int.Parse(s.Split(' ')[j]);
                    }
                }

                s = Console.ReadLine();
                guess2 = int.Parse(s);
                for (int i = 0; i < 4; i++)
                {
                    s = Console.ReadLine();
                    for (int j = 0; j < 4; j++)
                    {
                        board2[i, j] = int.Parse(s.Split(' ')[j]);
                    }
                }

                string ret = Solve(board1, board2, guess1, guess2);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string Solve(int[,] board1, int[,] board2, int guess1, int guess2)
        {
            bool[] poss = new bool[17];
            for (int i = 0; i < 4; i++)
            {
                poss[board1[guess1 - 1, i]] = true;
            }

            int ans = 0;
            for (int i = 0; i < 4; i++)
            {
                if (poss[board2[guess2 - 1, i]])
                {
                    if (ans != 0) return "Bad magician!";
                    ans = board2[guess2 - 1, i];
                }
            }

            if (ans == 0) return "Volunteer cheated!";
            return ans.ToString();
        }
    }
}
