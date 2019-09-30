using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC109_B();
        }

        static void ABC109_B()
        {
            var N = int.Parse(Console.ReadLine());
            var W = new HashSet<string>();
            for (var n = 0; n < N; n++)
                W.Add(Console.ReadLine());

            if (W.Count != N)
            {
                Console.WriteLine("No");
                return;
            }

            var list = W.ToList();
            var isShiritori = true;
            for (var n = 0; n < N-1; n++)
            {
                if (list[n].Last() != list[n + 1].First())
                {
                    isShiritori = false;
                    break;
                }
            }
            Console.WriteLine(isShiritori ? "Yes" : "No");
        }
    }
}