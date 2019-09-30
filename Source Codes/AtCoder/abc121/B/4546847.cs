using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int ans = 0;
            string[] s = Console.ReadLine().Split(' ');

            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            int C = int.Parse(s[2]);

            string[] bs = Console.ReadLine().Split(' ');

            int[] b = new int[M];

            for(int i=0;i<M;i++)
            {
                b[i] = int.Parse(bs[i]);
            }

            for(int i=0;i<N;i++)
            {
                string[] a = Console.ReadLine().Split(' ');
                int buf = C;

                for (int j = 0; j < M; j++)
                    buf += b[j] * int.Parse(a[j]);

                if (buf > 0)
                    ans++;
                
            }

            Console.WriteLine(ans.ToString());
        }
    }
}