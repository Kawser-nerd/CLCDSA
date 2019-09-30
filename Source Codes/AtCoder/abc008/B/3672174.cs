using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - ??
            int n = int.Parse(Console.ReadLine());

            var candidates = new Dictionary<string, int>();

            for(int i = 0; i < n; i++)
            {
                var name = Console.ReadLine();

                if (candidates.ContainsKey(name))
                {
                    candidates[name]++;
                }
                else
                {
                    candidates.Add(name, 1);
                }
            }

            int max = candidates.Max(x => x.Value);
            string winner = candidates.First(x => x.Value == max).Key;
            Console.WriteLine(winner);
        }
    }
}