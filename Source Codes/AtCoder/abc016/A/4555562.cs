using System;
using System.Linq;

namespace ABC016A
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var M = line[0]; var D = line[1];

            if(M % D == 0)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}