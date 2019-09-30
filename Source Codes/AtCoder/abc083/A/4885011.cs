using System;
using System.Linq;

namespace A___Libra
{
    class Program
    {
        static void Main(string[] args)
        {
            var A_B_C_D = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var A = A_B_C_D[0];
            var B = A_B_C_D[1];
            var C = A_B_C_D[2];
            var D = A_B_C_D[3];

            Console.WriteLine(A + B == C + D ? "Balanced" : (A + B > C + D ? "Left" : "Right"));
        }
    }
}