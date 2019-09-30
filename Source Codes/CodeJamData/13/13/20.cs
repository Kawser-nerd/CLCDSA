using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution
{
    static int numFactors(int number, int divisor)
    {
        int numDivisors = 0;
        while (number % divisor == 0)
        {
            numDivisors++;
            number = number / divisor;
        }
        return numDivisors;
    }

    static void Main(String[] args)
    {
        int T = int.Parse(Console.ReadLine());
        string[] rnmk = Console.ReadLine().Split();
        int R = int.Parse(rnmk[0]);
        int N = int.Parse(rnmk[1]);
        int M = int.Parse(rnmk[2]);
        int K = int.Parse(rnmk[3]);

        Random random = new Random();

        string results = "Case #1:\n";

        for (int i = 0; i < R; i++)
        {
            int num2 = 0, num3 = 0, num4 = 0, num5 = 0;
            int[] Ks = Console.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
            for (int j = 0; j < Ks.Length; j++)
            {
                num2 = Math.Max(num2, numFactors(Ks[j], 2));
                num3 = Math.Max(num3, numFactors(Ks[j], 3));
                num4 = Math.Max(num4, numFactors(Ks[j], 4));
                num5 = Math.Max(num5, numFactors(Ks[j], 5));
            }

            int undecidedNum = N - num3 - num5;
            for (int j = 0; j < num3; j++)
            {
                results += "3";
            }
            for (int j = 0; j < num5; j++)
            {
                results += "5";
            }

            if (undecidedNum == num2)
            {
                for (int j = 0; j < num2; j++)
                {
                    results += "2";
                }
            }
            else if (undecidedNum == num4)
            {
                for (int j = 0; j < num4; j++)
                {
                    results += "4";
                }
            }
            else
            {
                for (int j = 0; j < undecidedNum; j++)
                {
                    results += random.Next(2, M+1).ToString();
                }
            }

            results += "\n";
        }

            Console.WriteLine(results);
        
    }
}