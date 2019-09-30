using System;
using System.Collections.Generic;

namespace ABC114_C
{
    class Program
    {
        static long N;
        static List<int> num = new List<int>() { 3, 5, 7 };

        static void Main(string[] args)
        {
            N = int.Parse(Console.ReadLine());

            Console.WriteLine(dfs(0));
        }

        static long dfs(long number)
        {
            if (number > N)
            {
                return 0;
            }

            long ans = number.ToString().Contains("3")
                && number.ToString().Contains("5")
                && number.ToString().Contains("7") ? 1 : 0;

            foreach (var n in num)
            {
                ans += dfs(number * 10 + n);
            }

            return ans;
        }
    }
}