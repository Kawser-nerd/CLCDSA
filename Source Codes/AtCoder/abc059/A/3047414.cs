using System;

namespace ABC059A
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');

            Console.Write((char)('A' + (bufs[0][0] - 'a')));
            Console.Write((char)('A' + (bufs[1][0] - 'a')));
            Console.Write((char)('A' + (bufs[2][0] - 'a')));

            Console.WriteLine();
        }
    }
}