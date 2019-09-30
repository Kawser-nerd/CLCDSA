using System;

namespace ABC076B
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int K = int.Parse(Console.ReadLine());

            int res = 1;
            for (int i = 0; i < N; i++)
            {
                if (res < K)
                {
                    res <<= 1;
                }
                else
                {
                    res += K;
                }
            }

            Console.WriteLine(res);
        }
    }
}