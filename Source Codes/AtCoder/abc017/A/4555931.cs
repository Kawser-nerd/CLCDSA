using System;
using System.Linq;

namespace ABC017A
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] s = new int[3];
            int[] e = new int[3];

            for(var i = 0; i < 3; i++)
            {
                var line = Console.ReadLine().Split(' ').Select(t => int.Parse(t)).ToArray();
                s[i] = line[0];
                e[i] = line[1];
            }

            int total = 0;

            for(var i = 0; i < 3; i++)
            {
                total += s[i] * e[i];
            }

            Console.WriteLine(total / 10);
        }
    }
}