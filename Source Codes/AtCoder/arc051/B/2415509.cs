using System;

namespace arc051_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long[] ret = new long[45]; ret[1] = 1; ret[2] = 1;
            for (int i = 3; i < 45; i++) ret[i] = ret[i - 1] + ret[i - 2];
            Console.WriteLine(ret[n] + " " + ret[n + 1]);
        }
    }
}