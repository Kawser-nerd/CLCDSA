using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC113_C();
        }

        static void ABC113_C()
        {
            var NM = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var N = NM[0];
            var M = NM[1];
            var PY = new Dictionary<string, string>();
            var dict = new Dictionary<int, List<int>>();

            for (var m = 0; m < M; m++)
            {
                var py = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                if (!dict.ContainsKey(py[0]))
                    dict.Add(py[0], new List<int>());

                PY.Add($"{py[0]}{py[1]}", "");
                dict[py[0]].Add(py[1]);
            }

            foreach (var key in dict.Keys)
            {
                if (dict[key].Count > 1)
                    dict[key].Sort();
            }

            foreach (var key in dict.Keys)
            {
                var number = 1;
                foreach (var year in dict[key])
                {
                    PY[$"{key}{year}"] = $"{key:000000}{number:000000}";
                    number++;
                }
            }

            foreach (var value in PY.Values)
                Console.WriteLine(value);
        }
    }
}