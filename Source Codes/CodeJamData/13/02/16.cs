using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class LawnMower : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                int i = int.Parse(s.Split(' ')[0]);
                int j = int.Parse(s.Split(' ')[1]);
                int[,] lawn = new int[i, j];
                for (int a = 0; a < i; a++)
                {
                    s = Console.ReadLine();
                    string[] s2 = s.Split(' ');
                    for (int b = 0; b < j; b++)
                    {
                        lawn[a, b] = int.Parse(s2[b]);
                    }
                }
                string ret = canLawn(lawn,i,j);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string canLawn(int[,] lawn, int N, int M)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    bool canHoriz = true;
                    bool canVert = true;
                    for (int i2 = 0; i2 < N; i2++)
                    {
                        if (lawn[i2, j] > lawn[i, j])
                        {
                            canHoriz = false;
                        }
                    }

                    for (int j2 = 0; j2 < M; j2++)
                    {
                        if (lawn[i, j2] > lawn[i, j])
                        {
                            canVert = false;
                        }
                    }

                    if (!canHoriz && !canVert)
                    {
                        return "NO";
                    }
                }
            }

            return "YES";
        }

    }
}
