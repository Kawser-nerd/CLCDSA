using System;

namespace ISEC20181109
{
    class ZishoshikiJunjo
    {
        public static string Solve()
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