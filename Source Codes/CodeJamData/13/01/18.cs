using System;
using System.IO;

namespace Tic_Tac_Toe_Tomek
{
    internal class Program
    {
        private static readonly int[,] pole = new int[4,4];

        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            //string filename = @"A-small-attempt1.in.txt";
            string filename = @"A-large.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            bool full = true;
            for (int i = 0; i < 4; i++)
            {
                string line;
                do
                {
                    line = reader.ReadLine();
                    if (line == null)
                        throw new Exception("line null");
                    line = line.Trim();
                } while (line.Length != 4);


                for (int j = 0; j < 4; j++)
                {
                    switch (line[j])
                    {
                        case 'X':
                            pole[i, j] = 1;
                            break;
                        case 'O':
                            pole[i, j] = 2;
                            break;
                        case 'T':
                            pole[i, j] = 3;
                            break;
                        case '.':
                            pole[i, j] = 0;
                            full = false;
                            break;
                    }
                }
            }

            string result = full ? "Draw" : "Game has not completed";


            for (int i = 0; i < 4; i++)
            {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (pole[i, j] == 0)
                        break;
                    if ((pole[i, j] & 1) != 0)
                        c1++;
                    if ((pole[i, j] & 2) != 0)
                        c2++;
                }

                if (c1 == 4)
                {
                    result = "X won";
                    goto fin;
                }
                if (c2 == 4)
                {
                    result = "O won";
                    goto fin;
                }
            }

            for (int i = 0; i < 4; i++)
            {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (pole[j, i] == 0)
                        break;
                    if ((pole[j, i] & 1) != 0)
                        c1++;
                    if ((pole[j, i] & 2) != 0)
                        c2++;
                }

                if (c1 == 4)
                {
                    result = "X won";
                    goto fin;
                }
                if (c2 == 4)
                {
                    result = "O won";
                    goto fin;
                }
            }

            
            {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (pole[j, j] == 0)
                        break;
                    if ((pole[j, j] & 1) != 0)
                        c1++;
                    if ((pole[j, j] & 2) != 0)
                        c2++;
                }

                if (c1 == 4)
                {
                    result = "X won";
                    goto fin;
                }
                if (c2 == 4)
                {
                    result = "O won";
                    goto fin;
                }
            }

            {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (pole[3-j, j] == 0)
                        break;
                    if ((pole[3-j, j] & 1) != 0)
                        c1++;
                    if ((pole[3-j, j] & 2) != 0)
                        c2++;
                }

                if (c1 == 4)
                {
                    result = "X won";
                    goto fin;
                }
                if (c2 == 4)
                {
                    result = "O won";
                    goto fin;
                }
            }

            fin:
            Console.WriteLine("Case #{0}: {1}", C, result);
            writer.WriteLine("Case #{0}: {1}", C, result);
        }
    }
}