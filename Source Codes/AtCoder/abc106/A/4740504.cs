using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] A_B = Console.ReadLine().Split(' ');
            int a = int.Parse(A_B[0]);
            int b = int.Parse(A_B[1]);
            Console.WriteLine((a - 1) * (b - 1));
        }
    }
}