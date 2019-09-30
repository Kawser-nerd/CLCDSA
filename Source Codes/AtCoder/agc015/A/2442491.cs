using System;
using System.Linq;
namespace AGC015A
{
    class Program
    {
        static void Main()
        {
            long[] nab = Console.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
            if (nab[1] > nab[2])
            {
                Console.WriteLine(0);
                Environment.Exit(0);
            }
            if (nab[0] == 1 && nab[1] != nab[2])
            {
                Console.WriteLine(0);
                Environment.Exit(0);
            }
            long max = (nab[0] - 1) * nab[2] + nab[1];
            long min = (nab[0] - 1) * nab[1] + nab[2];
            Console.WriteLine(max - min + 1);
        }
    }
}