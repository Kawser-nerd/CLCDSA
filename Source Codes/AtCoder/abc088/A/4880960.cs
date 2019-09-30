using System;

namespace A___Infinite_Coins
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var A = int.Parse(Console.ReadLine());

            Console.WriteLine(A >= N % 500 ? "Yes" : "No");
        }
    }
}