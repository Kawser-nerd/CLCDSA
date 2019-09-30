using System;

namespace app
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str;
            str = Console.ReadLine().Split(' ');
            long A = long.Parse(str[0]), B = long.Parse(str[1]);
            
            long ans = Find(B) - Find(A-1);
            Console.WriteLine(ans);
        }

        static long Find(long n)
        {
            long cnt = 0;
            int d = Digit(n);

            for (int i = d - 1; i >= 0; i--) {
                int t = (int)((n / (long)Math.Pow(10, i)) % 10);

                if (t < 4) {
                    cnt += Sub(i) * t;
                } else if (t == 4) {
                    cnt += Sub(i) * t;
                    cnt += n % (long)Math.Pow(10, i) + 1;
                    break;
                } else if (4 < t && t < 9) {
                    cnt += Sub(i) * t;
                    cnt += (long)Math.Pow(10, i) - Sub(i);
                } else {
                    cnt += Sub(i) * t;
                    cnt += (long)Math.Pow(10, i) - Sub(i);
                    cnt += n % (long)Math.Pow(10, i) + 1;
                    break;
                }
            }

            return cnt;
        }

        static long Sub(long r)
        {
            long cnt = 0;
            long p = 1;
            for (int i = 0; i < r; i++) {
                if (i == 0) {
                    cnt = 2;
                } else {
                    cnt = cnt * 10 + p * 2 - cnt * 2;
                }
                p *= 10;
            }

            return cnt;
        }

        static int Digit(long num)
        {
            // Mathf.Log10(0)?NegativeInfinity?????????????
            return (num == 0) ? 1 : ((int)Math.Log10(num) + 1);
        }
    }
}