using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;

namespace Code_Jam_Qualification_Round
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader SR = new StreamReader(@"C:\Users\evelyne\Desktop\A-large.in");
            StreamWriter SW = new StreamWriter(@"C:\Users\evelyne\Desktop\A-large.out");

            string line;
            string[] words;
            int NoTests = 0;

            line = SR.ReadLine();
            NoTests = Int32.Parse(line);
            Int64 n, A, B, C, D, x0, y0, M, X, Y;

            for (int Q = 1; Q <= NoTests; ++Q)
            {
                Int64[,] lvl1 = new Int64[3, 3], lvl2 = new Int64[3, 3], lvl3 = new Int64[3, 3];

                line = SR.ReadLine();
                words = line.Split();

                n = Int32.Parse(words[0]);
                A = Int32.Parse(words[1]);
                B = Int32.Parse(words[2]);
                C = Int32.Parse(words[3]);
                D = Int32.Parse(words[4]);
                x0 = Int32.Parse(words[5]);
                y0 = Int32.Parse(words[6]);
                M = Int32.Parse(words[7]);

                X = x0;
                Y = y0;

                lvl1[X % 3, Y % 3] += 1;

                for (int i = 1; i < n; ++i)
                {
                    X = (A * X + B) % M;
                    Y = (C * Y + D) % M;

                    for (int ki = 0; ki < 3; ++ki)
                        for (int kj = 0; kj < 3; ++kj)
                            lvl3[(X + ki) % 3, (Y + kj) % 3] += lvl2[ki, kj];

                    for (int ki = 0; ki < 3; ++ki)
                        for (int kj = 0; kj < 3; ++kj)
                            lvl2[(X + ki) % 3, (Y + kj) % 3] += lvl1[ki, kj];

                    lvl1[X % 3, Y % 3] += 1;
                }


                SW.Write("Case #{0}: {1}", Q, lvl3[0,0]);
                SW.WriteLine();
            }

            SW.Flush();
            SW.Close();
        }
    }
}
