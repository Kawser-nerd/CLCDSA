using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - Time Limit Exceeded
            var line = ReadLine();
            int n = line[0];
            int t = line[1];

            var fares = GetFares(n, t).ToList();

            if (fares.Count == 0)
            {
                Console.WriteLine("TLE");
            }
            else
            {
                Console.WriteLine(fares.Min());
            }
        }

        static IEnumerable<int> GetFares(int n, int t)
        {
            for(int i = 0; i < n; i++)
            {
                var line = ReadLine();
                int cost = line[0];
                int time = line[1];

                if (time <= t)
                {
                    yield return cost;
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