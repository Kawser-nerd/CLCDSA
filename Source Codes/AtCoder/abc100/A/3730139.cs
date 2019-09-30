using System;

namespace HappyBirthday_
{
    class Program
    {
        public static string Solve()
        {
            string input = Console.ReadLine();
            int cutA = int.Parse(input.Split()[0]);
            int cutB = int.Parse(input.Split()[1]);
            // TDKR=A???KMR=B??
            if (cutA <= 8 && cutB <= 8)
            {
                // ??????
                return "Yay!";
            }
            // ???????????
            return ":(";
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}