using System;

namespace Beginner012B
{
    class Program
    {
        static void Main(string[] args)
        {
            var bathTime = TimeSpan.FromSeconds(int.Parse(Console.ReadLine()));
            Console.WriteLine(bathTime.ToString("hh':'mm':'ss"));
        }
    }
}