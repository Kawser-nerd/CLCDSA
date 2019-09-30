using System;
using System.IO;

namespace Lawnmower
{
    class Program
    {
        private static bool PossibleToCut(int rows, int cols, int[][] lawn, int[] maxRows, int[] maxCols)
        {
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    if ((lawn[r][c] < maxRows[r]) && (lawn[r][c] < maxCols[c])) return false;
                }
            }

            return true;
        }

        static void Main(string[] args)
        {
            try
            {
                string path = @"C:\Work\Trainings\Code Jam\2013 Qualification\B. Lawnmower\";
                string filenameIn = "B-large.in";
                string filenameOut = "B-large.out";

                StreamReader sr = new StreamReader(path + filenameIn);
                StreamWriter sw = new StreamWriter(path + filenameOut);

                int testCount = Convert.ToInt32(sr.ReadLine());

                for (int t = 0; t < testCount; t++)
                {
                    string[] splitted = sr.ReadLine().Split(' ');
                    int rows = Convert.ToInt32(splitted[0]);
                    int cols = Convert.ToInt32(splitted[1]);

                    int[][] lawn = new int[rows][];
                    for (int r = 0; r < rows; r++)
                    {
                        splitted = sr.ReadLine().Split(' ');
                        if (splitted.Length != cols) throw new ApplicationException("Wrong");

                        lawn[r] = new int[cols];
                        for (int c = 0; c < cols; c++)
                        {
                            lawn[r][c] = Convert.ToInt32(splitted[c]);
                        }
                    }

                    int[] maxRows = new int[rows];
                    int[] maxCols = new int[cols];

                    for (int r = 0; r < rows; r++)
                    {
                        for (int c = 0; c < cols; c++)
                        {
                            maxRows[r] = Math.Max(maxRows[r], lawn[r][c]);
                            maxCols[c] = Math.Max(maxCols[c], lawn[r][c]);
                        }
                    }

                    string message = PossibleToCut(rows, cols, lawn, maxRows, maxCols) ? "YES" : "NO";
                    sw.WriteLine("Case #{0}: {1}", (t + 1), message);
                }

                sr.Close();
                sw.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
