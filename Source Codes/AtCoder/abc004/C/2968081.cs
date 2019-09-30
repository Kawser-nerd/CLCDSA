using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_004
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            n %= 30;
            var card = new int[6] { 1, 2, 3, 4, 5, 6 };
            for (int i = 0; i < n; i++)
            {
                int swapIndex = i % 5;
                card[swapIndex + 1] += card[swapIndex];
                card[swapIndex] = card[swapIndex + 1] - card[swapIndex];
                card[swapIndex + 1] -= card[swapIndex];
            }
            string s = card[0].ToString() + card[1].ToString() + card[2].ToString()
                + card[3].ToString() + card[4].ToString() + card[5].ToString();
            Console.WriteLine(s);
        }
    }
}