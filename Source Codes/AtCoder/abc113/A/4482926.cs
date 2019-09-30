using System;

namespace AtCoderBC113A_DiscountFare
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');

            int Ans = int.Parse(s[0]) + int.Parse(s[1]) / 2;

            Console.WriteLine(Ans.ToString());
        }
    }
}