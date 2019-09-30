using System;

namespace ABC079_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            long L0 = 2;
            long L1 = 1;
            for (int i = 2; i <= N; i++)
            {
                long L2 = L1 + L0;
                L0 = L1;
                L1 = L2;
            }
            Console.WriteLine(L1);
        }
    }
}