using System;
using System.Collections.Generic;

namespace ConsoleApp6
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var ans = 0;
            for (int i = 0; i < 4; i++)
            {
                if (s[i].ToString() == "+")
                {
                    ans++;
                }
                else
                {
                    ans--;
                }
            }
            Console.WriteLine(ans);
        }
    }
}