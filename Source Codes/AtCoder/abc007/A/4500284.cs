using System;

namespace ABC007_A
{
    class Program
    {
        static string Solve()
        {
            int input = int.Parse(Console.ReadLine());
            string ans = (input - 1).ToString();
            return ans;
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}