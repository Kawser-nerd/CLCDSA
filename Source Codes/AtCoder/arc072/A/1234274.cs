using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ARC072
{
    public class C
    {
        private long[] A;

        private long F(int x)
        {
            bool positive = (x & 1) != 0;
            bool force = (x & 2) != 0;

            long result = 0;

            long current;

            if (force)
            {
                if (positive)
                {
                    current = 1;
                    result += Math.Abs(A[0] - 1);
                }
                else
                {
                    current = -1;
                    result += Math.Abs(-A[0] - 1);
                }
            }
            else
            {
                current = A[0];
                if (current == 0)
                {
                    result += 1;
                    current = (positive ? 1 : -1);
                }
            }

            bool nextUp = (current < 0);

            foreach (var a in A.Skip(1))
            {
                current += a;
                if (nextUp)
                {
                    if (current <= 0)
                    {
                        result += (-current + 1);
                        current = 1;
                    }
                }
                else
                {
                    if (current >= 0)
                    {
                        result += (current + 1);
                        current = -1;
                    }
                }
                nextUp ^= true;
            }

            return result;
        }

        private void Run()
        {
            var n = int.Parse(Console.ReadLine().Trim());
            A = Console.ReadLine().Trim().Split().Select(long.Parse).ToArray();
            Console.WriteLine(Enumerable.Range(0, 4).Select(F).Min());
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new C().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}