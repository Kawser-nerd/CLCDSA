using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - ????
            var originalMap = GetMap();

            //??????????
            var seas = GetSeaPostions(originalMap).ToList();

            //??????????????(1????????? +1)
            var targetCount = 101 - seas.Count;

            foreach(var sea in seas)
            {
                //?????????
                var map = new char[10, 10];
                Array.Copy(originalMap, map, 100);

                //??1?????????
                map[sea.Y, sea.X] = 'o';

                //????????????????????????
                var isReached = new bool[10, 10];

                //??????
                Search(map, isReached, sea.Y, sea.X);

                int count = CountReachedLands(isReached);

                if (count == targetCount)
                {
                    Console.WriteLine("YES");
                    return;
                }
            }

            Console.WriteLine("NO");
        }

        static int CountReachedLands(bool[,] isReached)
        {
            int count = 0;

            for(int y = 0; y < 10; y++)
            {
                for(int x = 0; x < 10; x++)
                {
                    if (isReached[y, x])
                    {
                        count++;
                    }
                }
            }

            return count;
        }

        static void Search(char[,] map, bool[,] isReached, int y, int x)
        {
            if (x < 0 | x > 9 | y < 0 | y > 9)
            {
                return;
            }
            else if (map[y, x] == 'x')
            {
                return;
            }
            else
            {
                if (!isReached[y, x])
                {
                    isReached[y, x] = true;

                    Search(map, isReached, y - 1, x);
                    Search(map, isReached, y + 1, x);
                    Search(map, isReached, y, x - 1);
                    Search(map, isReached, y, x + 1);
                }
            }
        }

        static IEnumerable<Position> GetSeaPostions(char[,] map)
        {
            for(int y = 0; y < 10; y++)
            {
                for(int x = 0; x < 10; x++)
                {
                    if(map[y, x]== 'x')
                    {
                        var pos = new Position(y, x);
                        yield return pos;
                    }
                }
            }
        }
        
        static char[,] GetMap()
        {
            var map = new char[10, 10];

            for(int y = 0; y < 10; y++)
            {
                var line = Console.ReadLine();
                var array = line.ToCharArray();
                
                for(int x = 0; x < 10; x++)
                {
                    map[y, x] = array[x];
                }
            }

            return map;
        }
    }

    class Position
    {
        public int X { set; get; }
        public int Y { set; get; }

        public Position(int y = 0, int x = 0)
        {
            Y = y;
            X = x;
        }
    }
}