using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Rotate
{
    class Program
    {
        static void Main(string[] args)
        {
            bool consoleOut = false;

            string caseFile = "large";
            string outFile = "out." + caseFile + ".txt";
            string inFile = "in." + caseFile + ".txt";
            System.IO.StreamReader sr = new System.IO.StreamReader(inFile);
            System.IO.TextWriter sw = consoleOut ? System.Console.Out : new System.IO.StreamWriter(outFile);

            int t = int.Parse(sr.ReadLine());
            for (int ccase = 0; ccase < t; ccase++)
            {
                string line = sr.ReadLine();
                string[] split = line.Split(' ');
                int n = int.Parse(split[0]);
                int k = int.Parse(split[1]);

                char[][] board = new char[n][];

                for (int i = 0; i < n; i++)
                {
                    board[i] = sr.ReadLine().ToCharArray();
                }

                char[][] rot = new char[n][];
                for (int i = 0; i < n; i++)
                {
                    rot[i] = new char[n];
                }

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        rot[j][n - i - 1] = board[i][j];
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    for (int kk = 0; kk < n; kk++)
                        for (int j = n - 2; j >= 0; j--)
                        {
                            if (rot[j + 1][i] == '.')
                            {
                                char tmp = rot[j + 1][i];
                                rot[j + 1][i] = rot[j][i];
                                rot[j][i] = tmp;
                            }
                        }
                }

                bool wonRed = false;
                bool wonBlue = false;

                //find hor
                for (int i = 0; i < n; i++)
                {
                    char w = winner(rot[i], k);
                    wonBlue = wonBlue || w == 'A' || w == 'B';
                    wonRed = wonRed || w == 'A' || w == 'R';
                }

                //find vert
                for (int i = 0; i < n; i++)
                {
                    List<char> col = new List<char>();
                    for (int j = 0; j < n; j++)
                    {
                        col.Add(rot[j][i]);
                    }
                    char w = winner(col.ToArray(), k);
                    wonBlue = wonBlue || w == 'A' || w == 'B';
                    wonRed = wonRed || w == 'A' || w == 'R';
                }

                //find diag


                for (int j = 0; j < n; j++)
                {
                    char[] list = Program.createDiag(rot, 0, j, 1, 1);
                    char w = winner(list, k);
                    wonBlue = wonBlue || w == 'A' || w == 'B';
                    wonRed = wonRed || w == 'A' || w == 'R';

                    list = Program.createDiag(rot, 0, j, 1, -1);
                    w = winner(list, k);
                    wonBlue = wonBlue || w == 'A' || w == 'B';
                    wonRed = wonRed || w == 'A' || w == 'R';
                }

                for (int j = 0; j < n; j++)
                {
                    char[] list = Program.createDiag(rot, n-1, j, -1, 1);
                    char w = winner(list, k);
                    wonBlue = wonBlue || w == 'A' || w == 'B';
                    wonRed = wonRed || w == 'A' || w == 'R';

                    list = Program.createDiag(rot, n-1, j, -1, -1);
                    w = winner(list, k);
                    wonBlue = wonBlue || w == 'A' || w == 'B';
                    wonRed = wonRed || w == 'A' || w == 'R';
                }



                sw.WriteLine("Case #" + (ccase + 1) + ": " + (wonRed && wonBlue ? "Both" : wonRed ? "Red" : wonBlue ? "Blue" : "Neither"));
            }


            if (consoleOut)
                System.Console.ReadLine();
            sw.Close();
        }
        private static char winner(char[] list, int k)
        {
            char last = '.';
            int count = 0;
            bool wonRed = false;
            bool wonBlue = false;
            for (int i = 0; i < list.Length; i++)
            {
                if (list[i] == last)
                    count++;
                else
                {
                    count = 0;
                }
                if (count >= k - 1)
                {
                    wonRed = wonRed | last == 'R';
                    wonBlue = wonBlue | last == 'B';
                    count -= k - 1;
                }
                last = list[i];
            }
            return wonRed && wonBlue ? 'A' : wonRed ? 'R' : wonBlue ? 'B' : '.';
        }

        private static char[] createDiag(char[][] list, int i, int j, int diri, int dirj)
        {
            List<char> res = new List<char>();
            while (i < list.Length && j < list.Length && j>=0 && i>=0)
            {
                res.Add(list[i][j]);
                i += diri;
                j += dirj;
            }
            return res.ToArray();
        }
    }
}
