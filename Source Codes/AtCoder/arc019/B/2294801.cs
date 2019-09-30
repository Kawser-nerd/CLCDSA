using System;

namespace arc019_2
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int n = s.Length;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != s[n - i - 1]) count++;
            }
            if (n == 1) Console.WriteLine(0);
            else
            {
                long ret = 25 * n;
                if (count == 0) Console.WriteLine(n % 2 == 0 ? ret : ret - 25);
                else Console.WriteLine(count == 2 ? ret - 2 : ret);
            }
        }
    }
}