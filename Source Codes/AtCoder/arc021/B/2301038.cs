using System;

namespace arc021_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long[] a = new long[n];
            long xor = 0;
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
                xor ^= a[i];
            }
            if (xor != 0) Console.WriteLine(-1);
            else
            {
                Console.WriteLine(0); long back = 0;
                for (int i = 1; i < n; i++)
                {
                    Console.WriteLine(back ^ a[i - 1]);
                    back ^= a[i - 1];
                }
            }
        }
    }
}