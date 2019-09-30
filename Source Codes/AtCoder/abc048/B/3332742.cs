using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - Between a and b ...
            var lines = ReadLines<long>(1).ToList();
            long a = lines[0][0];
            long b = lines[0][1];
            long x = lines[0][2];

            long count = GetDivisorsCount(a, b, x);

            Console.WriteLine(count);
        }

        static long GetDivisorsCount(long a, long b, long x)
        {
            long divisorsA = a / x;
            long divisorsB = b / x;
            long diff = divisorsB - divisorsA;

            if (a % x == 0)
            {
                diff++;
            }

            return diff;
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
                    else if (typeof(T) == typeof(long))
                    {
                        var numbers = list.ConvertAll(long.Parse);
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