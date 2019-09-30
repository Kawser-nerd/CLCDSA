using System;

namespace ConsoleApp39
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] array = Console.ReadLine().Split(' ');
            int X = int.Parse(array[0]);
            int Y = int.Parse(array[1]);

            if (X > Y)
            {
                Console.WriteLine(X);
            }
            else
            {
                Console.WriteLine(Y);
            }
        }
    }
}