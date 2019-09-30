using System;
using System.Linq;

namespace A.Cats_and_Dogs
{
    class Program
    {
        static void Main(string[] args)
        {
            var ABX = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var A = ABX[0];
            var B = ABX[1];
            var X = ABX[2];

            bool flg1 = X >= A;
            bool flg2 = X <= A + B;

            Console.WriteLine(flg1 && flg2 ? "YES" : "NO");
        }
    }
}