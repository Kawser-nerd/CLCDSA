using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemC
{
    class Program
    {
        class Messages
        {
            public const string IMPOSSIBLE = "Impossible";
        }

        static List<int> impossibleNumbers = new List<int>(new int[] { 2, 3, 5, 7 });

        static void Main(string[] args)
        {
            int numberOfTestCases = int.Parse(Console.ReadLine());

            for (int i = 0; i < numberOfTestCases; i++)
            {
                Console.WriteLine("Case #{0}:", i + 1);
                Trial();
            }
        }

        static void Trial()
        {
            var testCase = Console.ReadLine().Split(' ').Select((x) => (int.Parse(x)));

            int height = testCase.ElementAt(0);
            int width = testCase.ElementAt(1);
            int numberOfMines = testCase.ElementAt(2);
            int numberOfFreeSpace = width * height - numberOfMines;

            bool[,] map = new bool[width, height];
            
            if (width == 1)
            {
                for (int y = 0; y < numberOfMines; y++)
                {
                    map[0, y] = true;
                }
                ShowMap(map, width, height);
                return;
            }
            else if (height == 1)
            {
                Fill(map, 0, numberOfMines, true);
                ShowMap(map, width, height);
                return;
            }
            else if (width == 2)
            {
                if (numberOfFreeSpace == 1)
                {
                    for (int y = 0; y < height - 1; y++)
                    {
                        Fill(map, y, 2, true);
                    }
                    Fill(map, height - 1, 1, true);
                }
                else if (numberOfMines % 2 > 0 || numberOfFreeSpace < 4)
                {
                    Console.WriteLine(Messages.IMPOSSIBLE);
                    return;
                }
                else {
                    for (int y = 0; y < numberOfMines / 2; y++) 
                    {
                        Fill(map, y, 2, true);
                    }
                }
                ShowMap(map, width, height);
                return;
            }
            else if (height == 2)
            {
                if (numberOfFreeSpace == 1)
                {
                    Fill(map, 0, width, true);
                    Fill(map, 1, width - 1, true);
                }
                else if (numberOfMines % 2 > 0 || numberOfFreeSpace < 4)
                {
                    Console.WriteLine(Messages.IMPOSSIBLE);
                    return;
                }
                else
                {
                    Fill(map, 0, numberOfMines / 2, true);
                    Fill(map, 1, numberOfMines / 2, true);
                }
                ShowMap(map, width, height);
                return;
            }

            if (impossibleNumbers.Contains(numberOfFreeSpace))
            {
                Console.WriteLine(Messages.IMPOSSIBLE);
                return;
            }

            if (numberOfMines < width * (height - 2) - 2)
            {
                for (int y = 0; (y + 1) * width <= numberOfMines; y++)
                {
                    Fill(map, y, width, true);
                }
                if (numberOfMines % width <= width - 2)
                {
                    Fill(map, numberOfMines / width, numberOfMines % width, true);
                }
                else
                {
                    Fill(map, numberOfMines / width, numberOfMines % width - 1, true);
                    Fill(map, numberOfMines / width + 1, 1, true);
                }
            }
            else if (numberOfMines == width * height - 1)
            {
                for (int y = 0; y < height; y++) 
                {
                    Fill(map, y, width, true);
                }
                map[width - 1, height - 1] = false;
            }
            else
            {
                for (int y = 0; y + 3 < height; y++)
                {
                    Fill(map, y, width, true);
                    numberOfMines -= width;
                }

                int firstLine = numberOfMines / 3 + numberOfMines % 3;
                int otherLines = numberOfMines / 3;
                Fill(map, height - 3, firstLine, true);
                Fill(map, height - 2, otherLines, true);
                Fill(map, height - 1, otherLines, true);
            }

            ShowMap(map, width, height);
        }


        static void Fill(bool[,] map, int row, int count, bool value)
        {
            for (int i = 0; i < count; i++)
            {
                map[i, row] = value;
            }
        }

        static void ShowMap(bool[,] map, int width, int height)
        {
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    if (x + 1 == width && y + 1 == height)
                    {
                        Console.Write('c');
                    }
                    else
                    {
                        Console.Write(map[x, y] ? '*' : '.');
                    }
                }
                Console.WriteLine();
            }
        }
    }
}
