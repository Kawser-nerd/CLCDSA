using System;
using System.Linq;

namespace A___Expired
{
    class Program
    {
        static void Main(string[] args)
        {
            var X_A_B = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int X = X_A_B[0], A = X_A_B[1], B = X_A_B[2];

            Console.WriteLine(A >= B ? "delicious" : X + A >= B ? "safe" : "dangerous");
        }
    }
}