using System;
using System.Linq;

namespace ABC008B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            string[] S = new string[N];

            for(var i = 0; i < N; i++)
            {
                S[i] = Console.ReadLine();
            }

            var vote = S.GroupBy(s => s).OrderByDescending(s => s.Count());
            Console.WriteLine(vote.ElementAt(0).Key);
            
        }
    }
}