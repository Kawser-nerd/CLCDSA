using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static List<int> aDivisors;
        static List<int> bDivisors;
        static List<int> commonDivisors;

        static void Main(string[] args)
        {
            //[summary]B - K-th Common Divisor
            var line = ReadLine();
            int a = line[0];
            int b = line[1];
            int k = line[2];

            aDivisors = GetDivisors(a).ToList();
            bDivisors = GetDivisors(b).ToList();

            //????????????
            commonDivisors = GetCommonDivisors().OrderByDescending(x => x).ToList();

            //K????????????
            Console.WriteLine(commonDivisors[k - 1]);
        }

        static IEnumerable<int> GetCommonDivisors()
        {
            foreach(var d in aDivisors)
            {
                if (bDivisors.Contains(d))
                {
                    yield return d;
                }
            }
        }

        static IEnumerable<int> GetDivisors(int num)
        {
            for(int i = 1; i <= num; i++)
            {
                if (num % i == 0)
                {
                    yield return i;
                }
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