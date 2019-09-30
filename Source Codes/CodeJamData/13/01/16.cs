using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class TicTacToeTomek : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string[] s = new string[4];
                for (int i = 0; i < 4; i++)
                {
                    s[i] = Console.ReadLine();
                }
                string ret = ticsolve(s);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                Console.ReadLine();

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string ticsolve(string[] s)
        {
            int[] iStart = new int[] { 0, 0, 0, 0, 0, 1, 2, 3, 0, 3 };
            int[] jStart = new int[] { 0, 1, 2, 3, 0, 0, 0, 0, 0, 0 };
            int[] iDir = new int[] { 1, 1, 1, 1, 0, 0, 0, 0, 1, -1 };
            int[] jDir = new int[] { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 };

            bool draw = true;
            for (int dir = 0; dir < 10; dir++)
            {
                bool allX = true;
                bool allO = true;
                for (int a = 0; a < 4; a++)
                {
                    int i = iStart[dir] + a * iDir[dir];
                    int j = jStart[dir] + a * jDir[dir];
                    char c = s[i][j];
                    if (c == 'X') allO = false;
                    if (c == 'O') allX = false;
                    if (c == '.')
                    {
                        allO = false;
                        allX = false;
                        draw = false;
                    }
                }
                if (allX) return "X won";
                if (allO) return "O won";
            }
            if (draw) return "Draw";
            return "Game has not completed";
        }

    }
}
