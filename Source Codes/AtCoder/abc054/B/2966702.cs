using System;

namespace ABC054B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int N = Int32.Parse(bufs[0]);
            int M = Int32.Parse(bufs[1]);
            string[] A = new string[N];
            string[] B = new string[M];

            bool res = false;

            for (int i = 0; i < N; i++)
            {
                A[i] = Console.ReadLine();
            }
            for (int i = 0; i < M; i++)
            {
                B[i] = Console.ReadLine();
            }

            int cur = -1;
            int seek = 0;

            while (seek < (N - M + 1))
            {
                cur = A[seek].IndexOf(B[0], cur + 1);
                seek++;
                if (cur != -1)
                {
                    int j = 1;
                    while (j < M)
                    {
                        if (A[seek].IndexOf(B[j], cur, M) != cur) { break; }
                        seek++;
                        j++;
                    }
                    if (j >= M)
                    {
                        res = true;
                    }
                }
            }

            Console.WriteLine(res ? "Yes" : "No");
            return;
        }

    }
}