using System;
using System.Text.RegularExpressions;

namespace Beginner017B
{
    class Program
    {
        static void Main(string[] args)
        {
            var regex = new Regex("^(ch|o|k|u)*$");

            Console.WriteLine(regex.IsMatch(Console.ReadLine()) ? "YES" : "NO");
        }
    }
}