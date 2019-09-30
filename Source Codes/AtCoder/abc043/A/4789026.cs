using System;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            Console.WriteLine(Enumerable.Range(1, N).Sum());
        }
    }