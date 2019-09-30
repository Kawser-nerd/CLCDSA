using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            AGC012_A();
        }

        static void AGC012_A()
        {
            var N = int.Parse(Console.ReadLine());
            var an = Console.ReadLine().Split(' ').Select(long.Parse).OrderByDescending(x => x).ToArray();
            var dict = new Dictionary<int, List<long>>()
;
            for (var i = 0; i < N; i++)
                dict.Add(i, new List<long>());

            var k = 0;
            while (k < an.Length)
            {
                for (var i = 0; i < N; i++)
                {
                    dict[i].Add(an[k]);
                    k++;
                    if (k == an.Length) break;
                    dict[i].Add(an[k]);
                    k++;
                    if (k == an.Length) break;
                }
            }
            Console.WriteLine(dict.Values.Sum(x => x[1]));
        }
    }
}