using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Template
{
    public class Program
    {
        private const string InputFileName = @"C:\disk\input.in";
        private const string OutputFileName = @"C:\disk\output.out";

        public static void Main()
        {
            using (StreamReader sr = new StreamReader(InputFileName))
            using (StreamWriter sw = new StreamWriter(OutputFileName))
            {
                int numberOfTests = int.Parse(sr.ReadLine());
                for (int testNumber = 1; testNumber <= numberOfTests; testNumber++)
                {
                    //input
                    string[] line = sr.ReadLine().Split(' ');
                    int rows = int.Parse(line[0]);
                    int columns = int.Parse(line[1]);
                    char[,] painting = new char[rows, columns];
                    int[] rowBlues = new int[rows];
                    int[] columnBlues = new int[columns];
                    for (int row = 0; row < rows; row++)
                    {
                        string currentRow = sr.ReadLine();
                        for (int column = 0; column < columns; column++)
                        {
                            painting[row, column] = currentRow[column];
                            if (currentRow[column] == '#')
                            {
                                rowBlues[row]++;
                                columnBlues[column]++;
                            }
                        }
                    }

                    //logic
                    bool possible = true;
                    for (int row = 0; row < rows && possible; row++)
                    {
                        if (rowBlues[row] % 2 == 1)
                        {
                            possible = false;
                        }
                    }
                    for (int column = 0; column < columns && possible; column++)
                    {
                        if (columnBlues[column] % 2 == 1)
                        {
                            possible = false;
                        }
                    }
                    for (int row = 0; row < rows - 1 && possible; row++)
                    {
                        for (int column = 0; column < columns - 1 && possible; column++)
                        {
                            if (painting[row, column] == '#')
                            {
                                possible = TryPaint(painting, row, column);
                            }
                        }
                    }
                    if (possible)
                    {
                        possible = CheckIfPainted(painting);
                    }

                    Console.WriteLine("Case #{0}:", testNumber);
                    sw.WriteLine("Case #{0}:", testNumber);

                    if (!possible)
                    {
                        Console.WriteLine("Impossible");
                        sw.WriteLine("Impossible");
                    }
                    else
                    {
                        for (int row = 0; row < rows; row++)
                        {
                            for (int column = 0; column < columns; column++)
                            {
                                Console.Write(painting[row, column]);
                                sw.Write(painting[row, column]);
                            }
                            Console.WriteLine();
                            sw.WriteLine();
                        }
                    }
                }
            }
        }

        private static bool TryPaint(char[,] painting, int row, int column)
        {
            bool possible = 
                painting[row, column] == '#' &&
                painting[row + 1, column] == '#' &&
                painting[row, column + 1] == '#' &&
                painting[row + 1, column + 1] == '#';
            if (possible)
            {
                painting[row, column] = '/';
                painting[row + 1, column + 1] = '/';
                painting[row + 1, column] = '\\';
                painting[row, column + 1] = '\\';
            }
            return possible;
        }

        private static bool CheckIfPainted(char[,] painting)
        {
            for (int row = 0; row < painting.GetLength(0); row++)
            {
                for (int column = 0; column < painting.GetLength(1); column++)
                {
                    if (painting[row, column] == '#')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}
