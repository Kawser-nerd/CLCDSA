using System;

namespace ABC057D
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int N = Int32.Parse(bufs[0]);
            int A = Int32.Parse(bufs[1]);
            int B = Int32.Parse(bufs[2]);
            long[] v = new long[N];

            bufs = Console.ReadLine().Split(' ');
            for (int i = 0; i < N; i++)
            {
                v[i] = Int64.Parse(bufs[i]);
            }

            Array.Sort(v);

            double max = 0.0;
            for (int i = 1; i <= A; i++)
            {
                max += v[N - i];
            }

            Console.WriteLine((max / A).ToString("F6")); // Max of average

            long res = 0;

            long cur = v[N - A];
            int same = 1;
            int right = 1;
            int j = N - A - 1;
            while (j >= 0 && cur == v[j]) // Left
            {
                same++;
                j--;
            }
            j = N - A + 1;
            while (j < N && cur == v[j]) // Right
            {
                same++;
                right++;
                j++;
            }

            int term = N - (A - right);

            res = Combination(same, right);

            A++;
            while ((N >= A) && (B >= A) && (v[N - A] == v[N - 1]))
            {
                res += Combination(same, A);
                A++;
            }

            Console.WriteLine(res);
        }

        static long Combination(int tot, int num)
        {
            long res = 1;
            int tmp = 1;
            if ((tot / 2) < num)
            {
                num = tot - num;
            }

            for (int i = 0; i < num; i++)
            {
                res = res * tot / tmp;
                tot--;
                tmp++;
            }

            return res;
        }
    }
}