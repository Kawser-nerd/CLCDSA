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
            //[summary]B - Minesweeper
            var lines = ReadLines<int>(1).ToList();
            h = lines[0][0];
            w = lines[0][1];

            //???(???)???
            var map = ReadLines<char>(h).ToList();
            
            for(int i = 0; i < h; i++)
            {
                string s = "";

                for(int j = 0; j < w; j++)
                {
                    if (map[i][j] == '.')
                    {
                        int count = GetBombCount(map, i, j);
                        s += count;
                    }
                    else
                    {
                        s += "#";
                    }
                }

                Console.WriteLine(s);
            }
        }

        static int GetBombCount(List<List<char>> map, int posY, int posX)
        {
            int count = 0;

            for(int i = -1; i < 2; i++)
            {
                for(int j = -1; j < 2; j++)
                {
                    if(i == 0 && j == 0)
                    {
                        //?????
                    }
                    else
                    {
                        int y = posY + i;
                        int x = posX + j;

                        try
                        {
                            if (map[y][x] == '#')
                            {
                                count++;
                            }
                        }
                        catch (ArgumentOutOfRangeException)
                        {

                        }
                    }
                }
            }

            return count;
        }
                       
        static IEnumerable<List<T>> ReadLines<T>(int count = 0, char separator = ' ')
        {
            //[summary]??????????????List<T>??????????

            //???????????????1?????"count"????
            if (count == 0)
            {
                string line = Console.ReadLine().TrimEnd();
                count = int.Parse(line);
            }

            for (int i = 0; i < count; i++)
            {
                //??????1?????
                string line = Console.ReadLine().TrimEnd();

                //char?????1???????
                if (typeof(T) == typeof(char))
                {
                    var list = line.ToCharArray().ToList();
                    yield return (List<T>)(object)list;
                }
                else
                {
                    //???????"separator"????
                    var list = line.Split(separator).ToList();

                    //int??????????
                    if (typeof(T) == typeof(int))
                    {
                        var numbers = list.ConvertAll(int.Parse);
                        yield return (List<T>)(object)numbers;
                    }
                    else
                    {
                        yield return (List<T>)(object)list;
                    }
                }
            }
        }
    }
}