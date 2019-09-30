using System;

namespace arc055_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Console.Write(1);
            for (int i = 1; i < n; i++)
            {
                Console.Write(0);
            }
            Console.WriteLine(7);
        }
    }
}