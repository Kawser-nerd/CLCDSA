using System;

namespace ABC077_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = long.Parse(Console.ReadLine());
            long m=0;
            for (long i = 1; i*i <= N; i++)
                m = i;
            Console.WriteLine(m * m);
        }
    }
}