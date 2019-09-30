using System;

namespace ABC007_B
{
    class Program
    {
        static string Solve()
        {
            string input = Console.ReadLine();
            if (input != "a")
            {
                return "a";
            }
            return "-1";
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}