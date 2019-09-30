using System;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var AopB = Console.ReadLine().Split(' ').ToList();
            Console.WriteLine(AopB[1] == "+" ? int.Parse(AopB[0]) + int.Parse(AopB[2]) : int.Parse(AopB[0]) - int.Parse(AopB[2]));

        }
    }