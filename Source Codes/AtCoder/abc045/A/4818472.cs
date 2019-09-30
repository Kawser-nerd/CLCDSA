using System;

    class Program
    {
        static void Main(string[] args)
        {
            var a = int.Parse(Console.ReadLine());
            var b = int.Parse(Console.ReadLine());
            var h = int.Parse(Console.ReadLine());
            Console.WriteLine((a+b)*h/2);
        }
    }