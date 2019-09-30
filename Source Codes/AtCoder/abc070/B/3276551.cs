using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static List<List<char>> squares;

        static void Main(string[] args)
        {
            //[summary]B - Two Switches
            var lines = ReadLines<int>(1).ToList();
            int a = lines[0][0];
            int b = lines[0][1];
            int c = lines[0][2];
            int d = lines[0][3];

            int startTime;
            int endTime;

            if (a > c)
            {
                startTime = a;
            }
            else
            {
                startTime = c;
            }

            if (b > d)
            {
                endTime = d;
            }
            else
            {
                endTime = b;
            }

            int pushedTime = 0;

            if (endTime - startTime > 0)
            {
                pushedTime = endTime - startTime;
            }

            Console.WriteLine(pushedTime);
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