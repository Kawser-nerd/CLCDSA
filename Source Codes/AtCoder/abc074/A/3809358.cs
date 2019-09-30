using System;

namespace AtCoder
{
    class program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());int A = int.Parse(Console.ReadLine());
            Console.WriteLine(Math.Pow(N,2) - A);
        }
    }
}