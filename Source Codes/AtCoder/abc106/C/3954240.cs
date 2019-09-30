using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]C - To Infinity
            string s = Console.ReadLine();
            long k = long.Parse(Console.ReadLine());

            //S???????????????1????????
            int ones = CountContinuousOne(s);

            if (k <= ones)
            {
                Console.WriteLine(1);
            }
            else
            {
                Console.WriteLine(GetSecondChar(s));
            }
        }

        static int CountContinuousOne(string s)
        {
            int count = 0;

            foreach(var c in s)
            {
                if (c == '1')
                {
                    count++;
                }
                else
                {
                    break;
                }
            }

            return count;
        }

        static string GetSecondChar(string s)
        {
            foreach(var c in s)
            {
                if (c != '1')
                {
                    return c.ToString();
                }
            }

            return "1";
        }
    }
}