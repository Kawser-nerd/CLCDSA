using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC106_B();
        }

        static void ABC106_B()
        {
            var N = int.Parse(Console.ReadLine());
            var ans = 0;
            for (var n = 1; n <= N; n+=2)
            {
                var count = 0;
                for (var i = 1; i <=n; i++)
                {
                    if (n % i == 0)
                        count++;
                }
                if (count == 8)
                    ans++;
            }
            Console.WriteLine(ans);
        }
    }
}