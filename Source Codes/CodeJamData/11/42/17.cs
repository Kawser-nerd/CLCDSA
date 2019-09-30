using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace GCJ2011_r1
{
    struct Belt
    {
        public int length;
        public int speed;
    }

    class Program
    {
        static long LetterTolong(char l)
        {
            return l - 'a';
        }

        static char longToLetter(long i)
        {
            return (char)(i + 'a');
        }

        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("B-small-0.in");
            TextWriter tw = new StreamWriter("B-small-0.out");
            
            string line = tr.ReadLine();
            long numTest = long.Parse(line);

            for (long testi = 0; testi < numTest; testi++)
            {
                string[] elements = tr.ReadLine().Split(' ');
                int R = int.Parse(elements[0]);
                int C = int.Parse(elements[1]);
                int D = int.Parse(elements[2]);

                int[,] sheet = new int[R, C];

                for (int i = 0; i < R; i++)
                {
                    line = tr.ReadLine();

                    for (int j = 0; j < C; j++)
                    {
                        sheet[i, j] = int.Parse(line[j].ToString()) + D;
                    }
                }

                bool stop = false;

                for (int k = Math.Min(R,C); k >= 3; k--)
                {
                    for (int ioffset = 0; !stop && ioffset <= R - k; ioffset++)
                    {
                        for (int joffset = 0; !stop && joffset <= C - k; joffset++)
                        {
                            if (isBladeCentered(ioffset, joffset, k, sheet))
                            {
                                stop = true;
                            }
                        }
                    }

                    if (stop)
                    {
                        tw.WriteLine("Case #{0}: {1}", testi + 1, k);
                        Console.WriteLine("Case #{0}: {1}", testi + 1, k);
                        break;
                    }
                }

                if (!stop)
                {
                    tw.WriteLine("Case #{0}: {1}", testi + 1, "IMPOSSIBLE");
                    Console.WriteLine("Case #{0}: {1}", testi + 1, "IMPOSSIBLE");
                }
            }

            tr.Close();
            tw.Close();
            Console.ReadKey();
        }

        public static bool isBladeCentered(int iOffset, int jOffset, int k, int[,] sheet)
        {
            double centerY = iOffset + (double)k / 2.0;
            double centerX = jOffset + (double)k / 2.0;

            double sumX = 0;
            double sumY = 0;

            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    if (!((i == 0 && j == 0) || (i == k-1 && j == 0) || (i == 0 && j == k-1) || (i == k-1 && j == k-1)))
                    {
                        double coordY = iOffset + i + 0.5;
                        double coordX = jOffset + j + 0.5;

                        sumY += sheet[iOffset + i, jOffset + j] * (coordY - centerY);
                        sumX += sheet[iOffset + i, jOffset + j] * (coordX - centerX);
                    }
                }
            }

            if (Math.Abs(sumX) < 1e-6 && Math.Abs(sumY) < 1e-6)
                return true;
            else
                return false;
        }

        public static int CompareBelts(Belt b1, Belt b2)
        {
            if (b1.speed > b2.speed)
                return 1;
            else if (b1.speed == b2.speed)
                return 0;
            else
                return -1;
        }

        public static void reset(int[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    matrix[i, j] = -1;
                }
            }
        }

        public static void copyInto(int[,] matrix, int[,] other, int ioffset, int joffset)
        {
            for (int i = 0; i < other.GetLength(0); i++)
            {
                for (int j = 0; j < other.GetLength(1); j++)
                {
                    matrix[i + ioffset, j + joffset] = other[i, j];
                }
            }
        }

        public static bool isSymmetric(int[,] matrix)
        {
            int k = matrix.GetLength(0);

            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (matrix[i, j] != matrix[j, i])
                    {
                        if (matrix[i, j] == -1)
                            matrix[i, j] = matrix[j, i];
                        else if (matrix[j, i] == -1)
                            matrix[j, i] = matrix[i, j];
                        else
                            return false;
                    }
                }
            }

            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k - i - 1; j++)
                {
                    if (matrix[i, j] != matrix[k-1-j, k-1-i])
                    {
                        if (matrix[i, j] == -1)
                            matrix[i, j] = matrix[k - 1 - j, k - 1 - i];
                        else if (matrix[k - 1 - j, k - 1 - i] == -1)
                            matrix[k - 1 - j, k - 1 - i] = matrix[i, j];
                        else
                            return false;
                    }
                }
            }

            return true;
        }

        public static long sum(long[,] matrix)
        {
            
            long res = 0;
            for (long i = 0; i < matrix.GetLength(0); i++)
            {
                for (long j = 0; j < matrix.GetLength(1); j++)
                {
                    res += matrix[i, j];
                }
            }

            return res;
        }

        public static void cpymx(bool[,] matrixTo, bool[,] matrixFrom)
        {
            
            for (long i = 0; i < matrixTo.GetLength(0); i++)
            {
                for (long j = 0; j < matrixTo.GetLength(1); j++)
                {
                    matrixTo[i, j] = matrixFrom[i, j];
                }
            }
        }
    }
}
