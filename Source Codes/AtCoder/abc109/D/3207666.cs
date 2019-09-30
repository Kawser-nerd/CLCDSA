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
            //[summary]D - Make Them Even
            var lines = ReadLines<int>(1).ToList();
            h = lines[0][0];
            w = lines[0][1];

            //?????????
            var squares = ReadLines<int>(h).ToList();

            var histories = MoveZigZag(squares).ToList();

            Console.WriteLine(histories.Count);

            foreach(var s in histories)
            {
                Console.WriteLine(s);
            }
        }

        static IEnumerable<string> MoveZigZag(List<List<int>> squares)
        {
            //??????????????????????????
            var positions = new List<Position>();

            for(int i = 0; i < h * w; i++)
            {
                var position = new Position(i, h, w);
                positions.Add(position);
            }

            for(int i = 0; i < h * w - 1; i++)
            {
                int x = positions[i].X;
                int y = positions[i].Y;

                if (squares[y][x] % 2 == 1)
                {
                    int nextX = positions[i + 1].X;
                    int nextY = positions[i + 1].Y;

                    squares[y][x]--;
                    squares[nextY][nextX]++;

                    string s = string.Format("{0} {1} {2} {3}", y + 1, x + 1, nextY + 1, nextX + 1);
                    yield return s;
                }
            }
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

    class Position
    {
        public int X { set; get; }
        public int Y { set; get; }

        public Position(int i, int h, int w)
        {
            Y = i / w;
                        
            if (Y % 2 == 0)
            {
                X = i % w;
            }
            else
            {
                X = w - (i % w + 1);
            }            
        }
    }
}