using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static int h;
        static int w;

        static void Main(string[] args)
        {
            //[summary]B - Grid Compression
            var line = ReadLine();
            h = line[0];
            w = line[1];
            //?????????
            var grid = GetGrid().ToList();

            //?????????????????
            var whiteRow = CheckAllWhiteRow(grid).ToList();

            //?????????????????
            var whiteCol = CheckAllWhiteColumn(grid).ToList();

            //?????????????????,??????
            for(int i = 0; i < h; i++)
            {
                if (!whiteRow.Contains(i))
                {
                    string s = "";

                    for (int j = 0; j < w; j++)
                    {
                        if (!whiteCol.Contains(j))
                        {
                            s += grid[i][j];
                        }
                    }

                    Console.WriteLine(s);
                }                
            }
        }

        static IEnumerable<int> CheckAllWhiteRow(List<List<char>> grid)
        {
            for(int i = 0; i < h; i++)
            {
                bool isAllWhite = true;

                for(int j = 0; j < w; j++)
                {
                    if (grid[i][j] == '#')
                    {
                        isAllWhite = false;
                        break;
                    }
                }

                if (isAllWhite)
                {
                    yield return i;
                }
            }
        }

        static IEnumerable<int> CheckAllWhiteColumn(List<List<char>> grid)
        {
            for (int j = 0; j < w; j++)
            {
                bool isAllWhite = true;

                for (int i = 0; i < h; i++)
                {
                    if (grid[i][j] == '#')
                    {
                        isAllWhite = false;
                        break;
                    }
                }

                if (isAllWhite)
                {
                    yield return j;
                }
            }
        }

        static IEnumerable<List<char>> GetGrid()
        {
            for(int i = 0; i < h; i++)
            {
                var array = Console.ReadLine().ToCharArray();
                yield return array.ToList();
            }
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine().TrimEnd();
            var array = line.Split(' ');
            var numbers = new List<int>();

            foreach (var s in array)
            {
                int num = int.Parse(s);
                numbers.Add(num);
            }

            return numbers;
        }
    }
}