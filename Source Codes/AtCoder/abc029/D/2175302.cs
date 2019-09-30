using System;

namespace abc029_d
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = int.Parse(Console.ReadLine()); long ret = 0;
            for (long i = 1; i <= 10000000000; i *= 10)
            {
                long repeat = n / (i * 10);
                ret += repeat * i;
                ret += Math.Min(i,Math.Max(0,(n % (i * 10)) - i + 1));
            }
            Console.WriteLine(ret);
        }
    }
}