using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Minesweeper
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var inputValues = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    var R = inputValues[0];
                    var C = inputValues[1];
                    var M = inputValues[2];

                    bool success = false;

                    var allLocations = R * C;
                    var maxFullRows = M / C;
                    for (var fullRows = maxFullRows; fullRows >= 0; fullRows--)
                    {
                        var topOccupied = fullRows > 0;
                        var newR = R - fullRows;
                        var newM = M - fullRows * C;

                        var maxFullColumns = newM / newR;
                        var newC = C - maxFullColumns;
                        var leftOccupied = maxFullColumns > 0;
                        var leftoverMines = newM - maxFullColumns * newR;

                        if (leftoverMines >= newC)
                            continue;

                        var testMapRows = newR;
                        var firstTestRow = 0;
                        if (topOccupied)
                            firstTestRow++;
                        testMapRows += firstTestRow;

                        var testMapColumns = newC;
                        var firstTestColumn = 0;
                        if (leftOccupied)
                            firstTestColumn++;
                        testMapColumns += firstTestColumn;

                        var testMap = new bool[testMapColumns, testMapRows];
                        if (topOccupied)
                        {
                            for (var i = 0; i < testMapColumns; i++)
                                testMap[i, 0] = true;
                        }
                        if (leftOccupied)
                        {
                            for (var i = 0; i < testMapRows; i++)
                                testMap[0, i] = true;
                        }

                        success = AllocateAndTestMap(testMap, firstTestColumn, firstTestRow, leftoverMines, leftoverMines);

                        if (success)
                        {
                            outputStream.WriteLine("Case #{0}:", caseNumber);
                            for (var row = 0; row < fullRows - (topOccupied ? 1 : 0); row++)
                            {
                                for (var column = 0; column < C; column++)
                                {
                                    outputStream.Write("*");
                                }
                                outputStream.WriteLine();
                            }
                            for (var row = 0; row < testMap.GetLength(1); row++)
                            {
                                for (var column = 0; column < maxFullColumns - (leftOccupied ? 1 : 0); column++)
                                {
                                    outputStream.Write("*");
                                }
                                for (var column = 0; column < testMap.GetLength(0); column++)
                                {
                                    if (column == testMap.GetLength(0) - 1 && row == testMap.GetLength(1) - 1)
                                        outputStream.Write("c");
                                    else if (testMap[column, row])
                                        outputStream.Write("*");
                                    else
                                        outputStream.Write(".");
                                }
                                outputStream.WriteLine();
                            }
                            break;
                        }
                    }

                    if (!success)
                    {
                        outputStream.WriteLine("Case #{0}:", caseNumber);
                        outputStream.WriteLine("Impossible");
                    }
                }
            }
        }

        private static bool AllocateAndTestMap(bool[,] testMap, int firstTestColumn, int firstTestRow, int leftoverMines, int maxRowMines)
        {
            if (leftoverMines == 0)
            {
                return TestMap(testMap);
            }

            if (firstTestRow >= testMap.GetLength(1))
                return false;
            
            for (var i = maxRowMines; i >= 1; i--)
            {
                for (var x = 0; x < i; x++)
                {
                    testMap[firstTestColumn + x, firstTestRow] = true;
                }

                var success = AllocateAndTestMap(testMap, firstTestColumn, firstTestRow + 1, leftoverMines - i, (i < (leftoverMines - i)) ? i : leftoverMines - i);
                if (success)
                    return true;

                for (var x = 0; x < i; x++)
                {
                    testMap[firstTestColumn + x, firstTestRow] = false;
                }
            }

            return false;
        }

        private static bool TestMap(bool[,] testMap)
        {
            var distances = new int?[testMap.GetLength(0), testMap.GetLength(1)];
            for (var x = 0; x < testMap.GetLength(0); x++)
                for (var y = 0; y < testMap.GetLength(1); y++)
                    if (testMap[x, y])
                        distances[x, y] = -1;

            Shoot(distances, distances.GetLength(0) - 1, distances.GetLength(1) - 1);

            for (var x = 0; x < testMap.GetLength(0); x++)
                for (var y = 0; y < testMap.GetLength(1); y++)
                    if (!distances[x, y].HasValue)
                        return false;

            return true;
        }

        private static void Shoot(int?[,] distances, int x, int y)
        {
            if (x < 0 || x >= distances.GetLength(0))
                return;
            if (y < 0 || y >= distances.GetLength(1))
                return;
            if (distances[x, y].HasValue)
                return;

            var mines = 0;
            mines += Mine(distances, x - 1, y - 1);
            mines += Mine(distances, x, y - 1);
            mines += Mine(distances, x + 1, y - 1);
            mines += Mine(distances, x - 1, y);
            mines += Mine(distances, x + 1, y);
            mines += Mine(distances, x - 1, y + 1);
            mines += Mine(distances, x, y + 1);
            mines += Mine(distances, x + 1, y + 1);
            distances[x, y] = mines;
            if (mines == 0)
            {
                Shoot(distances, x - 1, y - 1);
                Shoot(distances, x, y - 1);
                Shoot(distances, x + 1, y - 1);
                Shoot(distances, x - 1, y);
                Shoot(distances, x + 1, y);
                Shoot(distances, x - 1, y + 1);
                Shoot(distances, x, y + 1);
                Shoot(distances, x + 1, y + 1);
            }
        }

        private static int Mine(int?[,] distances, int x, int y)
        {
            if (x < 0 || x >= distances.GetLength(0))
                return 0;
            if (y < 0 || y >= distances.GetLength(1))
                return 0;
            if (distances[x,y] == -1)
                return 1;
            return 0;
        }
    }
}
