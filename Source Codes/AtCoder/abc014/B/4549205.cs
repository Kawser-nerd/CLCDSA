using System;
using System.Linq;

namespace ABC014B
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().Split(' ').Select(t => int.Parse(t)).ToArray();
            var n = line[0];
            var X = line[1];
            

            var a = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

            int total = 0;

            for(var i = 0; i < n; i++)
            {
                if((X >> i & 1) == 1)
                {
                    total += a[i];
                }
            }

            Console.WriteLine(total);
        }
    }
}