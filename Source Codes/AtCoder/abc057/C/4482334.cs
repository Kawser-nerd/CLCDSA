using System;
using System.Numerics;

    class Program
    {
        static void Main(string[] args)
        {
            var N = BigInteger.Parse(Console.ReadLine());
            long result = N.ToString().Length;

            for (BigInteger A =1;A*A<=N;A++)
            {
                if (N % A != 0) continue;
                var B = N / A;
                var tmpCount = Math.Max(A.ToString().Length, B.ToString().Length);
                if (result > tmpCount) result = tmpCount;
            }
            Console.WriteLine(result);
        }
    }