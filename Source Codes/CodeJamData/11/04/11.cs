using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemD
{
    class Program
    {
        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                string[] str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int[] a = new int[n];
                int ans = 0;
                for (int i = 0; i < n; ++i)
                {
                    a[i] = Convert.ToInt32(str[i]);
                    if (a[i] != i + 1) ++ans;
                }
                Console.WriteLine("Case #{0}: {1}", curCase + 1, ans);
            }
        }
    }
}
