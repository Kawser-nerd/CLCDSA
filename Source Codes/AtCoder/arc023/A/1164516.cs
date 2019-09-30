using System;

namespace arc023_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int y = int.Parse(Console.ReadLine());
            int m = int.Parse(Console.ReadLine());
            int d = int.Parse(Console.ReadLine());
            if (m < 3)
            {
                y--;
                m += 12;
            }
            Console.WriteLine(735369 - (365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429));
        }
    }
}