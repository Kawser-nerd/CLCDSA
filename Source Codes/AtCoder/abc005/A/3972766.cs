using System;

namespace ConsoleApp39
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] array = Console.ReadLine().Split(' ');
            int n = int.Parse(array[0]);
            int m = int.Parse(array[1]);
                Console.WriteLine(m/n);

        }
    }
}