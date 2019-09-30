using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var c = Console.ReadLine();
            var d = Console.ReadLine();
            Console.WriteLine(c[0] == d[2] && c[1] == d[1] && c[2] == d[0]? "YES":"NO");
        }
    }
}