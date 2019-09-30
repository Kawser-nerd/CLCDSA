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
            //[summary]B - Training Camp
            var lines = ReadLines<int>(1).ToList();
            int n = lines[0][0];

            long remainder = CalcRemainder(n);
            Console.WriteLine(remainder);
        }

        static long CalcRemainder(int n)
        {
            long power = 1;
            int divisor = (int)Math.Pow(10, 9) + 7;

            for (int i = 1; i <= n; i++)
            {
                power *= i;

                if (power > divisor)
                {
                    power %= divisor;
                }
            }

            return power % divisor;
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