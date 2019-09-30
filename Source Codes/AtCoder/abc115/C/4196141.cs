using System;
using System.Collections.Generic;
using System.Linq;

namespace question3
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();
            p.Run();
        }

        void Run()
        {
            var line = Console.ReadLine();
            var n = int.Parse(line.Split(' ')[0]);
            var k = int.Parse(line.Split(' ')[1]);

            var h = new List<int>();
            var ans = int.MaxValue;

            for (int i = 0; i < n; i++)
            {
                h.Add(int.Parse(Console.ReadLine()));
            }
            h.Sort();

            for (int i = 0; i <= n - k; i++)
            {
                ans = Math.Min(ans, h[i + k - 1] - h[i]);
            }

            Console.WriteLine(ans);
        }
    }
}