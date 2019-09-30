using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - Choose Integers
            var lines = ReadLines<int>(1).ToList();

            if (IsSatisfyConditions(lines[0]))
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }        
        }

        static bool IsSatisfyConditions(List<int> numbers)
        {
            int a = numbers[0];
            int b = numbers[1];
            int c = numbers[2];

            for(int i = 1; i <= b; i++)
            {
                if (a * i % b == c)
                {
                    return true;
                }
            }

            return false;
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