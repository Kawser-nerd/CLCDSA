using System;

namespace A___Buying_Sweets
{
    class Program
    {
        static void Main(string[] args)
        {
            var X = int.Parse(Console.ReadLine());
            var A = int.Parse(Console.ReadLine());
            var B = int.Parse(Console.ReadLine());

            Console.WriteLine((X - A) % B);
        }
    }
}