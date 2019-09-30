using System;
using System.Linq;

namespace A___Two_Coins
{
    class Program
    {
        static void Main(string[] args)
        {
            var A_B_C = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var A = A_B_C[0];
            var B = A_B_C[1];
            var C = A_B_C[2];

            Console.WriteLine(A + B >= C ? "Yes" : "No");
        }
    }
}