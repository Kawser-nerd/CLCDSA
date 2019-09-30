using System;

namespace ABC076_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var r = int.Parse(Console.ReadLine());
            var g = int.Parse(Console.ReadLine());
            Console.WriteLine(2 * g - r);
        }
    }
}