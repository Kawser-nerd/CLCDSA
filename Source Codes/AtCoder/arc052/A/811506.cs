using System;
using System.Text.RegularExpressions;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(new Regex(@"[^0-9]").Replace(Console.ReadLine(), ""));
        }
    }
}