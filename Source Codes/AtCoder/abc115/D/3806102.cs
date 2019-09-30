using System;

namespace DChristmas
{
    class Solution
    {
        long[] burgerWidth;
        long[] pattiesWidth;


        public long GetNumberOfPattiesFromBurgerLevel(long n, long x)
        {
            if (x <= 0 || n < 0)
                return 0;

            burgerWidth = new long[ n + 1];
            pattiesWidth = new long[n + 1];

            burgerWidth[0] = 1;
            pattiesWidth[0] = 1;

            CalculateBurgerWidth(n);

            if (x > burgerWidth[n])
                return 0;

            return GetPattiesFrom(n,x);
        }

        public void CalculateBurgerWidth(long level)
        {
            for (int i = 1; i <= level; i++)
            {
                burgerWidth[i] = 2 * burgerWidth[i - 1] + 3;
                pattiesWidth[i] = 2 * pattiesWidth[i - 1] + 1;
            }
        }

        public long GetPattiesFrom(long n, long x)
        {
            if (n == 0)
            { 
                if (x <= 0)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else if(x > burgerWidth[n - 1] + 1)
            {
                return GetPattiesFrom(n - 1,  x - burgerWidth[n-1] - 2) + 1 + pattiesWidth[n-1];
            }
            else
            {
                return GetPattiesFrom(n - 1, x - 1);
            }
        }

        public long GetHamburgerWidthFromFirstLevel(long x)
        {
            if (x == 0)
                return 0;

            if (x < 5)
                return x - 1;

            return x - 2;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');

            long n = long.Parse(str[0]);
            long x = long.Parse(str[1]);

            Solution s = new Solution();

            Console.WriteLine(s.GetNumberOfPattiesFromBurgerLevel(n, x));
        }
    }
}