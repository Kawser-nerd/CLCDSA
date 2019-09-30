using System;
using System.Linq;

namespace A___Meal_Delivery
{
    class Program
    {
        static void Main(string[] args)
        {
            var x_a_b = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int x = x_a_b[0], a = x_a_b[1], b = x_a_b[2];

            Console.WriteLine(Math.Abs(x - a) < Math.Abs(x - b) ? "A" : "B");
        }
    }
}