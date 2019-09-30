using System;

namespace ABC013A
{
    class Program
    {
        static void Main(string[] args)
        {
            var X = Console.ReadLine();
            if (X == "A") Console.WriteLine(1);
            else if (X == "B") Console.WriteLine(2);
            else if (X == "C") Console.WriteLine(3);
            else if (X == "D") Console.WriteLine(4);
            else Console.WriteLine(5); 
        }
    }
}