using System;
using System.Linq;

namespace ABC070_A
{
    class Program
    {
        static string Solve()
        {
            string input = Console.ReadLine();
            string revInput = string.Join("", input.Reverse());
            if (input.Equals(revInput))
            {
                return "Yes";
            }
            return "No";
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}