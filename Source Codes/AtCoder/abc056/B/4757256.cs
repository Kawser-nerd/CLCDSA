using System;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();
            var W = input[0];
            var a = Math.Min(input[1], input[2]);
            var b = Math.Max(input[1], input[2]);
            Console.WriteLine(b - a - W <= 0 ? 0 : b - a - W);
        }
    }