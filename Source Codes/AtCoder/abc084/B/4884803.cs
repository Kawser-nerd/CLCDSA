using System;
using System.Linq;

namespace B___Postal_Code
{
    class Program
    {
        static void Main(string[] args)
        {
            var A_B = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var S = Console.ReadLine().Split('-').ToArray();
            var A = A_B[0];
            var B = A_B[1];

            Console.WriteLine(S[0].Length == A && S[1].Length == B ? "Yes" : "No");
        }
    }
}