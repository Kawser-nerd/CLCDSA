using System;
using System.Collections.Generic;
using System.Linq;

namespace B.Bitter_Alchemy
{
    class Program
    {
        static void Main(string[] args)
        {
            var NX = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var N = NX[0];
            var X = NX[1];

            var mi = new List<int>();

            for (int i = 0; i < N; i++)
            {
                mi.Add(int.Parse(Console.ReadLine()));
            }

            var cnt = mi.Count();

            for (int i = mi.Sum() + mi.Min(); i <= X; i += mi.Min())
            {
                cnt++;
            }

            Console.WriteLine(cnt);
        }
    }
}