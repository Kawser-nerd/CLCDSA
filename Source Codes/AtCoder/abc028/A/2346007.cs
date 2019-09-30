using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        public static void Main()
        {
            new Program().Solve();
        }

        void Solve()
        {
            var x = int.Parse(Console.ReadLine());
            string s;
            if (x <= 59)
            {
                s = "Bad";
            }
            else if (x <= 89)
            {
                s = "Good";
            }
            else if (x <= 99)
            {
                s = "Great";
            }
            else
            {
                s = "Perfect";
            }
            Console.WriteLine(s);
        }
    }
}