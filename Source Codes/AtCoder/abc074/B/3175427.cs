using System;

namespace ABC074B
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int K = int.Parse(Console.ReadLine());
            int med = K / 2;
            string[] bufs = Console.ReadLine().Split(' ');

            int res = 0;

            for (int i = 0; i < N; i++)
            {
                int pos = int.Parse(bufs[i]);
                if (pos <= med)
                {
                    res += pos << 1;
                }
                else
                {
                    res += (K - pos) << 1;
                }
            }

            Console.WriteLine(res);
        }
    }
}