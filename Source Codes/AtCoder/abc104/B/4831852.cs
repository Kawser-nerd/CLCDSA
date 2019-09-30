using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - AcCepted
            string s = Console.ReadLine();

            if (IsAccepted(s))
            {
                Console.WriteLine("AC");
            }
            else
            {
                Console.WriteLine("WA");
            }
        }

        static bool IsAccepted(string s)
        {
            if (s.StartsWith("A"))
            {
                if (CountLowers(s) == s.Length - 2)
                {
                    if (CountC(s) == 1)
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        static int CountLowers(string s)
        {
            var substring = s.Substring(1, s.Length - 1);
            int count = 0;

            foreach(var c in substring)
            {
                if (char.IsLower(c))
                {
                    count++;
                }
            }

            return count;
        }

        static int CountC(string s)
        {
            var substring = s.Substring(2, s.Length - 3);
            int count = 0;

            foreach (var c in substring)
            {
                if (c == 'C')
                {
                    count++;
                }
            }

            return count;
        }
    }
}