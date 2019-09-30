using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int ans = 0;

            if (n == 1 || n == 2)
            {
                ans = 0;
            }
            else if (n == 3)
            {
                ans = 1;
            }
            else
            {
                int[] a = new int[n+1];
                a[3] = 1;
                for(int i = 4; i <= n; i++)
                {
                    a[i] = a[i - 3] + a[i - 2] + a[i - 1];
                    a[i] %= 10007;
                }
                ans = a[n];
            }
            Console.WriteLine(ans);
        }
    }
}