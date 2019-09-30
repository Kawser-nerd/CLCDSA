/*  Author: Ben Olden-Cooligan
 *  Email: blue0fish@gmail.com
 *  Google Code Jam 2009 Question B
 */

using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Cylan.Extensions.Streaming.Text.WSV;

namespace CodeJam2009Qualification
{
    class ProgramB
    {
        static string input = "B-large.in";
        static string output = "B-large.out";

        static int H, W;
        static int[,] altitudes;
        static Basin[,] basins;

        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(input))
            {
                using (StreamWriter sw = new StreamWriter(output))
                {
                    int T = sr.ReadInt32WSV();
                    for (int i = 0; i < T; ++i)
                    {
                        H = sr.ReadInt32WSV();
                        W = sr.ReadInt32WSV();
                        altitudes = new int[H, W];
                        for (int j = 0; j < H; ++j)
                        {
                            for (int k = 0; k < W; ++k)
                            {
                                altitudes[j, k] = sr.ReadInt32WSV();
                            }
                        }

                        basins = new Basin[H, W];
                        for (int j = 0; j < H; ++j)
                        {
                            for (int k = 0; k < W; ++k)
                            {
                                WhichBasin(j, k);
                            }
                        }

                        char c = 'a';

                        sw.WriteLine("Case #{0}:", i + 1);
                        for (int j = 0; j < H; ++j)
                        {
                            for (int k = 0; k < W; ++k)
                            {
                                if (basins[j, k].Character == char.MinValue)
                                {
                                    basins[j, k].Character = c;
                                    c = (char)((int)c + 1);
                                }
                                sw.Write(basins[j, k].Character);
                                if (k != W - 1) sw.Write(" ");
                                else sw.WriteLine();
                            }
                        }
                    }
                }
            }
        }

        static Basin WhichBasin(int j, int k)
        {
            if (basins[j, k] != null) return basins[j, k];
            int a = altitudes[j, k];
            Basin b = null;
            //Prioritize in N, W, E, S order
            if (j > 0 && altitudes[j - 1, k] < a)
            {
                a = altitudes[j - 1, k];
                b = WhichBasin(j - 1, k);
            }
            if (k > 0 && altitudes[j, k - 1] < a)
            {
                a = altitudes[j, k - 1];
                b = WhichBasin(j, k - 1);
            }
            if (k < W - 1 && altitudes[j, k + 1] < a)
            {
                a = altitudes[j, k + 1];
                b = WhichBasin(j, k + 1);
            }
            if (j < H - 1 && altitudes[j + 1, k] < a)
            {
                a = altitudes[j + 1, k];
                b = WhichBasin(j + 1, k);
            }
            if (b == null)
            {
                b = new Basin() { Row = j, Column = k };
            }
            basins[j, k] = b;
            return b;
        }

        private class Basin
        {
            public int Row { get; set; }
            public int Column { get; set; }
            public char Character { get; set; }
        }
    }
}
