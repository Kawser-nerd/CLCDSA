using System;

namespace ABC011A
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());

            if(N <= 11)
            {
                Console.WriteLine(N + 1);
            }
            else
            {
                Console.WriteLine(1);
            }
        }
    }
}