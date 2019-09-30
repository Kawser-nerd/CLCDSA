using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - Grid Compression
            var line = ReadLine();
            int h = line[0];

            var grid = GetGrid(h).ToList();

            //????
            Compress(grid);

            foreach(var g in grid)
            {
                string s = String.Join("", g);
                Console.WriteLine(s);
            }
        }

        static void Compress(List<List<char>> grid)
        {
            int h = grid.Count;
            int w = grid[0].Count;
            bool isTryAgain = false;

            //????????
            for (int i = 0; i < h; i++)
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
                    grid.RemoveAt(i);
                    isTryAgain = true;
                    break;
                }
            }

            //???????????????
            h = grid.Count;

            //????????
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
                    for(int i = 0; i < h; i++)
                    {
                        grid[i].RemoveAt(j);
                    }

                    isTryAgain = true;
                    break;
                }
            }

            if (isTryAgain)
            {
                Compress(grid);
            }
        }

        static IEnumerable<List<char>> GetGrid(int h)
        {
            for(int i = 0; i < h; i++)
            {
                string line = Console.ReadLine();
                var array = line.ToCharArray();
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