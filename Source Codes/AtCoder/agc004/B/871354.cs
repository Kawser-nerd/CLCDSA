using System;
class Program
{
        static void Main(string[] args)
        {
                // ?????
                //int a = int.Parse(Console.ReadLine());
                // ?????????????
                string [] tmp = Console.ReadLine().Split(' ');
                long N = int.Parse(tmp[0]);
        long x = int.Parse(tmp[1]);
                string [] a = Console.ReadLine().Split(' ');
        long[,] b = new long[2001, 2001];

        for (int xx = 0; xx < 2001; xx++) {
            for (int yy = 0; yy < 2001; yy++) {
                b[xx, yy] = 0;
            }
        }

        long t = 0;
        long bl = 0;
                long s = 0;

        long ans = long.MaxValue;

        for (long k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                bl = (i < k) ? 1 : 0;
                t = i - k + N * bl;
                //Console.WriteLine(a[t]);
                if (k == 0) {
                    b[k, i] = int.Parse(a[t]);
                } else {
                    b[k, i] = Math.Min(b[k-1, i], int.Parse(a[t]));
                }
            }
            s = 0;
            for (int z = 0; z < N; z++) {
                s += b[k, z];
            }

            ans = Math.Min(s + x * k, ans);
            //Console.WriteLine(ans);
        }

                //??
                Console.WriteLine(ans);
        }
}