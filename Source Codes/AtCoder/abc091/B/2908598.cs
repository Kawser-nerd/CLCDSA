using System;
using System.Collections.Generic;
using System.Linq;

namespace arugo
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var dict = new Dictionary<string, int>();
            for (var n = 0; n < N; n++)
            {
                var word = Console.ReadLine();
                if (dict.ContainsKey(word))
                    dict[word]++;
                else
                    dict.Add(word, 1);
            }

            var M = int.Parse(Console.ReadLine());
            for (var m = 0; m < M; m++)
            {
                var word = Console.ReadLine();
                if (dict.ContainsKey(word))
                    dict[word]--;
                else
                    dict.Add(word, -1);
            }

            if (dict.Max(x => x.Value) > 0)
                Console.WriteLine(dict.Max(x => x.Value));
            else
                Console.WriteLine(0);
        }
    }
}