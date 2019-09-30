using System;

namespace ABC073B
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int res = 0;

            for (int i = 0; i < N; i++)
            {
                string[] bufs = Console.ReadLine().Split(' ');
                int left = int.Parse(bufs[0]);
                int right = int.Parse(bufs[1]);
                res += right - left + 1;
            }

            Console.WriteLine(res);
        }
    }
}