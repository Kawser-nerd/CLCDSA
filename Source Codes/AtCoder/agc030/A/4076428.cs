using System;

namespace A_PoisonousCookies
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();

            int A = int.Parse(s[0]);
            int B = int.Parse(s[1]);
            int C = int.Parse(s[2]);

            if (C <= A + B)
                Console.WriteLine((B + C).ToString());
            else
                Console.WriteLine((A + B + B +1).ToString());
        }
    }
}