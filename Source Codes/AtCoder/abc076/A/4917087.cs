using System;

namespace A___Rating_Goal
{
    class Program
    {
        static void Main(string[] args)
        {
            var R = double.Parse(Console.ReadLine());
            var G = double.Parse(Console.ReadLine());

            Console.WriteLine(2 * G - R);
        }
    }
}