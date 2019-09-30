using System;
using System.IO;
using System.Linq;

namespace tidy
{
    public class Solution
    {
        static void Main(string[] args)
        {
            //Console.SetIn(new StreamReader("B-large.in"));
            //Console.SetOut(new StreamWriter("large.out"));
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                long n = long.Parse(Console.ReadLine());
                long s = Solve(n);
                Console.WriteLine("Case #{0}: {1}", (i+1), s);
            }
            //Console.Out.Flush();
        }

        public static long Solve(long l)
        {
            // 101 - 99
            // 132 - 129
            // Go from right to left
            // When you encounter a number higher than the right, decrease by one and make all on the right 9
            string numberString = "" + l;
            int[] digits = numberString.Select(x => int.Parse(""+x)).ToArray();
            for (int i = digits.Length - 2; i >= 0; i--)
            {
                int left = digits[i];
                int right = digits[i + 1];
                if (left > right)
                {
                    digits[i]--;
                    for (int j = i+1; j < digits.Length; j++)
                    {
                        digits[j] = 9;
                    }
                }
            }
            string finalNumber = new string(digits.Select(x => (""+x)[0]).ToArray());
            finalNumber = finalNumber.TrimStart('0');
            long theNumber = long.Parse(finalNumber);
            return theNumber;
        }
    }
}
