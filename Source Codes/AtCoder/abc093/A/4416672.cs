using System;
using System.Linq;

namespace A.abc_of_ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();

            Console.WriteLine(S.Contains('a') && S.Contains('b') && S.Contains('c') ? "Yes" : "No");
        }
    }
}