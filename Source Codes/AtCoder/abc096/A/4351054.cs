using System;
using System.Linq;

namespace A.Day_of_Takahashi
{
    class Program
    {
        static void Main(string[] args)
        {
            var ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int a = ab[0];
            int b = ab[1];

            Console.WriteLine(b >= a ? a : a - 1);
        }
    }
}