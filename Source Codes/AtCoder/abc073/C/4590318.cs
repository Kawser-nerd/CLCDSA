using System;
using System.Collections.Generic;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var paper = new List<string>();

            for (int i=0;i<N;i++)
            {
                var tmp = Console.ReadLine();
                paper.Add(tmp);
            }
            var sum = paper.GroupBy(s => s).Select(g => g.Count() % 2 == 0 ? 0 : 1).Sum();
            Console.WriteLine(sum);
        }
    }