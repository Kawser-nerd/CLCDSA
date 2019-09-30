using System;
using System.Text.RegularExpressions;

namespace A___Good_Integer
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = Console.ReadLine();
            
            Console.WriteLine(Regex.IsMatch(N, @"(\d)\1{2}") ? "Yes" : "No");
        }
    }
}