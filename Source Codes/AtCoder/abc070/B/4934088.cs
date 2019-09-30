using System;
using System.Linq;

namespace B___Two_Switches
{
    class Program
    {
        static void Main(string[] args)
        {
            var A_B_C_D = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var AB = Enumerable.Range(A_B_C_D[0], A_B_C_D[1] - A_B_C_D[0] + 1).ToArray();
            var CD = Enumerable.Range(A_B_C_D[2], A_B_C_D[3] - A_B_C_D[2] + 1).ToArray();

            Console.WriteLine(AB.Intersect(CD).Any() ? Math.Max(0, AB.Intersect(CD).Count() - 1) : 0);
        }
    }
}