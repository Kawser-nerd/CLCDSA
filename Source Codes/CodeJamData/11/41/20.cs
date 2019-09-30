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
            TextReader tr = new StreamReader("A-large-0.in");
            TextWriter tw = new StreamWriter("A-large-0.out");
            
            string line = tr.ReadLine();
            long numTest = long.Parse(line);

            for (long testi = 0; testi < numTest; testi++)
            {
                string[] elements = tr.ReadLine().Split(' ');
                int X = int.Parse(elements[0]);
                int S = int.Parse(elements[1]);
                int R = int.Parse(elements[2]);
                int t = int.Parse(elements[3]);
                int N = int.Parse(elements[4]);

                Belt[] belts = new Belt[N + 1];

                int allLength = 0;

                for (int i = 0; i < N; i++)
                {
                    elements = tr.ReadLine().Split(' ');
                    belts[i].length = int.Parse(elements[1]) - int.Parse(elements[0]);
                    belts[i].speed = int.Parse(elements[2]);

                    allLength += belts[i].length;
                }

                belts[N].length = X - allLength;
                belts[N].speed = 0;

                Array.Sort(belts, CompareBelts);

                double runLeft = t;
                double totalTime = 0; 

                for (int i = 0; i < N+1; i++)
                {
                    if (runLeft >= (double)belts[i].length / (double)(belts[i].speed + R))
                    {
                        double currTime = (double)belts[i].length / (double)(belts[i].speed + R);
                        totalTime += currTime;
                        runLeft -= currTime;
                    }
                    else if (runLeft > 0)
                    {
                        double runLength = (belts[i].speed + R) * runLeft;

                        double leftLength = belts[i].length - runLength;

                        double leftTime = (double)leftLength / (double)(belts[i].speed + S);

                        totalTime += (runLeft + leftTime);
                        runLeft = 0;
                    }
                    else
                    {
                        double currTime = (double)belts[i].length / (double)(belts[i].speed + S);
                        totalTime += currTime;
                    }
                }


                CultureInfo cult = new CultureInfo("en-US");


                tw.WriteLine("Case #{0}: {1}", testi + 1,totalTime.ToString(cult) );
                Console.WriteLine("Case #{0}: {1}", testi + 1, totalTime.ToString(cult));
            }

            tr.Close();
            tw.Close();
            Console.ReadKey();
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
