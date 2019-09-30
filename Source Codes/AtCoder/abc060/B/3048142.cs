using System;

namespace ABC060B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int A = Int32.Parse(bufs[0]);
            int B = Int32.Parse(bufs[1]);
            int C = Int32.Parse(bufs[2]);

            int tmp = A;
            for (int i = 0; i < B; i++)
            {
                if (tmp % B == C)
                {
                    Console.WriteLine("YES");
                    return;
                }
                tmp += A;
            }

            Console.WriteLine("NO");
        }
    }
}