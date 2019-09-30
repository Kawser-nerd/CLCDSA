using System;

namespace arc098_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            int ret = 0;
            for (int i = 1; i < n; i++)
            {
                if (s[i] == 'E') ret++;
            }
            int now = ret;
            for (int i = 1; i < n; i++)
            {
                if (s[i - 1] == 'W') now++;
                if (s[i] == 'E') now--;
                ret = Math.Min(ret, now);
            }
            Console.WriteLine(ret);
        }
    }
}