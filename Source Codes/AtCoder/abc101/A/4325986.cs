using System;

namespace A.Eating_Symbols_Easy
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine().ToCharArray();
            var ans = 0;

            for (int i = 0; i < 4; i++)
                ans = S[i] == '+' ? ++ans : --ans;

            Console.WriteLine(ans);
        }
    }
}