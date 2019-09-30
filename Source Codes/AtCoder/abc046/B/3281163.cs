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
            //[summary]B - AtCoDeer????????? / Painting Balls with AtCoDeer
            var lines = ReadLines<int>(1).ToList();
            int n = lines[0][0];
            int k = lines[0][1];

            int combination = CalcCombinationCount(n, k);
            Console.WriteLine(combination);
        }

        static int CalcCombinationCount(int n, int k)
        {
            int count = k;

            for(int i = 1; i < n; i++)
            {
                count *= (k - 1);
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