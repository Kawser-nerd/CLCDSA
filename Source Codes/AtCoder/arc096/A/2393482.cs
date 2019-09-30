using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC096C
{
    class Program
    {
        static void Main(string[] args)
        {
            var ABCXY = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int A = ABCXY[0];
            int B = ABCXY[1];
            int C = ABCXY[2];
            int X = ABCXY[3];
            int Y = ABCXY[4];

            //A<B???
            if (A > B)
            {
                int temp = B;
                B = A;
                A = temp;
                temp = Y;
                Y = X;
                X = temp;
            }

            int ans = 0;
            if (A >= 2 * C)
            {
                ans = 2 * C * Math.Max(X, Y);
            }
            else if (B >= 2 * C)
            {
                ans = Y * 2 * C;
                if (X > Y) ans += A * (X - Y);
            }
            else if (A + B >= 2 * C)
            {
                if (X >= Y)
                {
                    ans = Y * 2 * C + A * (X - Y);
                }
                else
                {
                    ans = X * 2 * C + B * (Y - X);
                }
            }
            else
            {
                ans = A * X + B * Y;
            }

            Console.WriteLine(ans);
            Console.ReadKey();
        }
    }
}