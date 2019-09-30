using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - Break Number
            var n = int.Parse(Console.ReadLine());

            Console.WriteLine(GetMaxNumberMultipleOf2(n));
        }

        static int GetMaxNumberMultipleOf2(int n)
        {
            int lastNum = 1;
            int i = 1;

            while (true)
            {
                int newNum = (int)Math.Pow(2, i);

                if (newNum > n)
                {
                    return lastNum;
                }
                else
                {
                    lastNum = newNum;
                    i++;
                }
            }
        }
    }
}