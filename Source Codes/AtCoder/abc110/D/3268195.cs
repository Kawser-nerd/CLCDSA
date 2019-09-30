using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;

class program
{
    static long mod = 1000000007;
    static void Main(string[] args)
    {
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int N = input[0];
        int M = input[1];
        int[] indexes = index(M);
        BigInteger ans = 1;
        if (M!=1)
        {
            for (int i = 0; i < indexes.Count(); i++)
            {
                ans *= nHk(indexes[i]+N-1, N-1);
            }
        }

/*
        for (int i = 0; i < indexes.Length; i++)
        {
            Console.WriteLine(indexes[i]);
        }
*/

        Console.WriteLine(ans%mod);
    }

    static int[] index(int n)
    {
        var list = new List<int>();
        if (n==1)
        {
            list.Add(1);
        }
        else
        {
            int i = 2;
            int temp = 0;
            while (n!=1)
            {
                 if (n%i==0)
                 {
                    temp++;
                    n /= i;
                 }
                 else
                 {
                    if (temp != 0)
                    {
                        list.Add(temp);
                    }
                    temp = 0;
                    i++;
                 }
            }
            list.Add(temp);
        }
        int[] res = list.ToArray();
        return res;
    }

    static BigInteger nHk(int n, int r)
    {
        if (n < 0 || r < 0 || r > n) throw new ArgumentException("????????");

        if (n - r < r) r = n - r;
        if (r == 0) return 1;
        if (r == 1) return n;

        int[] numerator = new int[r];
        int[] denominator = new int[r];

        for (int k = 0; k < r; k++)
        {
            numerator[k] = n - r + k + 1;
            denominator[k] = k + 1;
        }

        for (int p = 2; p <= r; p++)
        {
            int pivot = denominator[p - 1];
            if (pivot > 1)
            {
                int offset = (n - r) % p;
                for (int k = p - 1; k < r; k += p)
                {
                    numerator[k - offset] /= pivot;
                    denominator[k] /= pivot;
                }
            }
        }
        BigInteger result = BigInteger.One;
        for (int k = 0; k < r; k++)
        {
            if (numerator[k] > 1) result *= numerator[k];
        }

        return result;
        /*
        long result;
        long temp1 = 1;
        for (int i = k; i < n+k; i++)
        {
            temp1 *= i;
            temp1 %= 
        }
        long temp2 = 1;
        for (int i = 1; i <= n ; i++)
        {
            temp2 *= i;
        }
        result = temp1 / temp2;
        Console.WriteLine(result);
        return result;
        */
    }
}