using System;

namespace ABC056B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int W = Int32.Parse(bufs[0]);
            int a = Int32.Parse(bufs[1]);
            int b = Int32.Parse(bufs[2]);

            int res = 0;

            if (b > (a + W))
            {
                res = b - (a + W);
            }
            else if (a > (b + W))
            {
                res = a - (b + W);
            }

            Console.WriteLine(res);
        }
    }
}