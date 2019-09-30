using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProgrammingContestPractice
{
    class Watersheds2
    {
        static void Main(string[] args)
        {
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Watersheds\\B-small-attempt0.in.txt";
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Watersheds\\B-small-attempt1.in.txt";
            string strInputFile = "C:\\GoogleCodeJamInputOutput\\Watersheds\\B-small-attempt2.in";
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Watersheds\\B-large-practice.in";
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Watersheds\\sample.in.txt";
            System.IO.TextReader tr = new StreamReader(strInputFile);
            System.IO.TextWriter tw = new StreamWriter(strInputFile + ".out.txt");
            int iTotalTestCases = Int32.Parse(tr.ReadLine());
            for (int iCase = 0; iCase < iTotalTestCases; iCase++)
            {
                String[] strLine = tr.ReadLine().Split(' ');
                long H = Int64.Parse(strLine[0]);
                long W = Int64.Parse(strLine[1]);
                alti = new int[H][];
                for (int r = 0; r < alti.Length; r++)
                {
                    alti[r] = tr.ReadLine().Split(' ').Select(x=>Int32.Parse(x)).ToArray();
                }

                currentBasin = 0;
                tw.WriteLine("Case #{0}:", (1+iCase));
                GetDMap(alti);
                foreach (var rr in basinMap)
                {
                    for(int cc = 0;cc<rr.Length; cc++)
                    {
                        if (cc > 0) Console.Write(" ");
                        tw.Write(rr[cc]);

                    }
                    tw.WriteLine();
                }
            }

            tr.Close();
            tw.Close();

            Console.WriteLine("press any key to continue");
            Console.ReadKey();
        }

        static string drainSig = "abcdefghijklmnopqrstuvwxyz";
        static int currentBasin = 0;
        static int[][] alti;
        static char[][] basinMap;

        private static void GetDMap(int[][] alti)
        {
            basinMap = new char[alti.Length][];
            int r;
            int c;
            for( r = 0; r < alti.Length; r++)
            {
                basinMap[r] = alti[r].Select(x => ' ').ToArray();
            }


            for (r = 0; r < alti.Length; r++)
            {
                for (c = 0; c < alti[r].Length; c++)
                {
                    basinMap[r][c] = FindBasin(r, c);
                }
            }

        }

        private static char FindBasin(int r, int c)
        {
            char cBasin = basinMap[r][c];
            if (cBasin != ' ') return cBasin;

            int[] drain = GetDrain(alti, r, c);
            if (drain == null)
            {
                return drainSig[currentBasin++];
            }
            else
            {
                cBasin = FindBasin(drain[0], drain[1]);
                basinMap[drain[0]][drain[1]] = cBasin;
                return cBasin;
            }
        }

        private static int[] GetDrain(int[][] alti, int rr, int cc)
        {
            int min = 99999;
            int[] minpos = null;
            int[][] directions = new int[][] { new int[] { 1, 0 }, new int[] { 0, 1 }, new int[] { 0, -1 }, new int[] { -1, 0 } };
            foreach (var pos in directions)
            {
                if (rr + pos[0] < 0) continue;
                if (rr + pos[0] >= alti.Length) continue;
                if (cc + pos[1] < 0) continue;
                if (cc + pos[1] >= alti[0].Length) continue;
                int posv = alti[rr+pos[0]][cc+pos[1]];
                if (posv < alti[rr][cc])
                {
                    if (posv <= min)
                    {
                        min = posv;
                        minpos = pos;
                    }
                }
            }
            if (minpos == null) return null;
            return new int[] { rr+ minpos[0], cc+minpos[1] };
        }
    }
}
