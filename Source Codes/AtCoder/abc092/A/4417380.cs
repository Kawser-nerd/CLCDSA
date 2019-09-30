using System;

namespace A___Traveling_Budget
{
    class Program
    {
        static void Main(string[] args)
        {
            var A = int.Parse(Console.ReadLine());
            var B = int.Parse(Console.ReadLine());
            var C = int.Parse(Console.ReadLine());
            var D = int.Parse(Console.ReadLine());

            var res = Math.Min(A, B) + Math.Min(C, D);

            Console.WriteLine(res);
        }
    }
}