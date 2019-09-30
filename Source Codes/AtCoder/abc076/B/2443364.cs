using System;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            var n = int.Parse(Console.ReadLine());
            var k = int.Parse(Console.ReadLine());
            int ans = 1;
            for (int i = 0; i < n; i++)
            {
                if (ans > k) ans += k;
                else ans *= 2;
            }
            Console.WriteLine(ans);
        }
    }
}