using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reg096C
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var A = s[0] < s[1] ? s[0] : s[1];
            var B = s[0] < s[1] ? s[1] : s[0];
            var C = s[2];
            var X = s[0] < s[1] ? s[3] : s[4];
            var Y = s[0] < s[1] ? s[4] : s[3];

            var ans = 0;
            int k, l, m;
            var isCAdvAB = 2 * C < A + B;
            var isCAdvA = 2 * C < A;
            var isCAdvB = 2 * C < B;
            if (!isCAdvAB)
                ans = A * X + B * Y;
            else if (isCAdvA || (isCAdvB && X<Y))
            {
                m = Math.Max(2 * X, 2 * Y);
                ans = m * C;
            }
            else
            {
                m = 2 * Math.Min(X, Y);
                k = X - m / 2;
                l = Y - m / 2;
                ans = A * k + B * l + C * m;
            }
            Console.WriteLine(ans);

        }
    }
}