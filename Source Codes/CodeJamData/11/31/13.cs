using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemB
{
    class Program
    {
        public static void GetOperationTile(int[,] matrix, int rows, int columns, out int operationTileRow, out int operationTileColumn)
        {
            operationTileRow = -1;
            operationTileColumn = -1;

            for (int j = columns - 1; j >= 0; j--)
            {
                for (int i = rows - 1; i >= 0; i--)
                {
                    if (matrix[i, j] == 1)
                    {
                        operationTileRow = i;
                        operationTileColumn = j;
                        return;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(@"D:\temp\CodeJam\ProblemB\Inputs\A-large.in"))
            {
                using (StreamWriter writer = new StreamWriter(@"D:\Temp\CodeJam\ProblemB\Outputs\A-large.out"))
                {
                    int inputCount = Convert.ToInt32(reader.ReadLine());

                    for (int i = 0; i < inputCount; i++)
                    {
                        string[] rowsAndColumnsStrings = reader.ReadLine().Split(' ');
                        int rows = Convert.ToInt32(rowsAndColumnsStrings[0]);
                        int columns = Convert.ToInt32(rowsAndColumnsStrings[1]);

                        int[,] matrix = new int[rows, columns];

                        for (int row = 0; row < rows; row++)
                        {
                            string lineString = reader.ReadLine();
                            
                            for (int column = 0; column < columns; column++)
                            {
                                char tileColor = lineString[column];

                                matrix[row, column] = tileColor == '.' ? 0 : 1;
                            }
                        }

                        bool impossible = false;

                        int operationTileRow;
                        int operationTileColumn;
                        GetOperationTile(matrix, rows, columns, out operationTileRow, out operationTileColumn);
                        while (operationTileRow != -1)
                        {
                            if (operationTileRow == 0)
                            {
                                impossible = true;
                                break;
                            }
                            if (operationTileColumn == 0)
                            {
                                impossible = true;
                                break;
                            }
                            if ((matrix[operationTileRow, operationTileColumn] != 1) ||
                                (matrix[operationTileRow-1, operationTileColumn] != 1) ||
                                (matrix[operationTileRow, operationTileColumn-1] != 1) ||
                                (matrix[operationTileRow-1, operationTileColumn-1] != 1))
                            {
                                impossible = true;
                                break;
                            }

                            //Replace!
                            matrix[operationTileRow, operationTileColumn] = 2;
                            matrix[operationTileRow-1, operationTileColumn] = 3;
                            matrix[operationTileRow, operationTileColumn-1] = 4;
                            matrix[operationTileRow-1, operationTileColumn-1] = 5;

                            GetOperationTile(matrix, rows, columns, out operationTileRow, out operationTileColumn);
                        }

                        if (impossible)
                        {
                            writer.WriteLine("Case #" + (i + 1).ToString() + ":");
                            writer.WriteLine("Impossible");
                        }
                        else
                        {
                            writer.WriteLine("Case #" + (i + 1).ToString() + ":");
                            for (int row = 0; row < rows; row++)
                            {
                                for (int column = 0; column < columns; column++)
                                {
                                    if (matrix[row, column] == 0)
                                        writer.Write('.');
                                    else if (matrix[row, column] == 2)
                                        writer.Write('/');
                                    else if (matrix[row, column] == 3)
                                        writer.Write('\\');
                                    else if (matrix[row, column] == 4)
                                        writer.Write('\\');
                                    else if (matrix[row, column] == 5)
                                        writer.Write('/');
                                }

                                writer.WriteLine();
                            }
                        }
                   }
                }
            }
        }
    }
}
