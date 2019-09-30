using System;

namespace ABC033_A
{
    class Program
    {
        static string Solve()
        {
            int pass = int.Parse(Console.ReadLine());
            if (pass%1111 == 0)
            {
                return "SAME";
            }
            return "DIFFERENT";
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}