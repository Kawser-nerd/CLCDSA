using System;
using System.Linq;

namespace A___Palindromic_Number
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = Console.ReadLine();

            Console.WriteLine(N.SequenceEqual(N.Reverse().ToArray()) ? "Yes" : "No");
        }
    }
}