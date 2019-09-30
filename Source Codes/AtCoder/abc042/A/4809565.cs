using System;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var ABC = Console.ReadLine().Split(' ').ToList();
            Console.WriteLine(ABC.Count(s => s == "5") == 2 && ABC.Count(s => s == "7") == 1 ? "YES" : "NO");
        }
    }