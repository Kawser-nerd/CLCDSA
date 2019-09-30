using System;
using System.Collections.Generic;

class ABC121_D
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        long A = long.Parse(input[0]);
        long B = long.Parse(input[1]);

        if(A==B)
        {
            Console.WriteLine(A);
            return;
        }

        long[] A2 = BitCountXOR(A-1);
        long[] B2 = BitCountXOR(B);

        long sum = 0;
        long exponential = 1;
        for (int i = 0; i < B2.Length; i++)
        {
            long a = i < A2.Length ? A2[i] : 0;
            long b = B2[i];

            if ((a+b) % 2 == 1)
            {
                sum += exponential;
            }
            exponential *= 2;
        }

        Console.WriteLine(sum);
    }

    static long[] BitCountXOR(long num)
    {
        List<long> digit = new List<long>();

        long quotient = num + 1;
        long exponential = 1;
        while (num > exponential/2)
        {
            long q = quotient / (exponential*2);
            long r = quotient % (exponential*2);
            long bit = r >= exponential ? r - exponential : 0;
            bit += q * exponential;
            exponential *= 2;
            digit.Add(bit);
        }

        return digit.ToArray();
    }
}