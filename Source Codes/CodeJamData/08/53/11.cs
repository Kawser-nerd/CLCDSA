using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static int N;
        static public int numbits(int num)
        {
            int result = 0;
            while (num != 0)
            {
                if(num % 2 == 1)
                    result++;
                num /= 2;
            }
            return result;
        }
        static public bool can(int num, string mask)
        {
            int temp = num % 2;
            num /= 2;
            int number = 0;
            if (temp == 1 && mask[0] == 'x')
                return false;

            while (num != 0)
            {
                number++;
                if (temp == 1 && num % 2 == 1)
                    return false;
                if (num % 2 == 1 && mask[number] == 'x')
                    return false;
                temp = num % 2;
                num /= 2;
            }
            return true;
        }
        static public bool can1(int num1, int num2)
        {
            for (int i = 0; i < N - 1; i++)
            {
                if ((num1 ^ (1 << i)) == num1 - (1 << i) && (num2 ^ (1 << (i + 1))) == num2 - (1 << (i + 1)))
                    return false;
            }
            for (int i = 1; i < N; i++)
            {
                if ((num1 ^ (1 << i)) == num1 - (1 << i) && (num2 ^ (1 << (i - 1))) == num2 - (1 << (i - 1)))
                    return false;
            }
            return true;
        }
        static void Main(string[] args)
        {
            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var T = int.Parse(sr.ReadLine());

            for (int z = 0; z < T; z++)
            {
                int M;
                string[] sarr = sr.ReadLine().Split(' ');
                M = int.Parse(sarr[0]);
                N = int.Parse(sarr[1]);
                List<string> ls = new List<string>();
                for (int i = 0; i < M; i++)
                    ls.Add(sr.ReadLine());

                int len = (1 << N);
                int[,] dp = new int[10, 1024];
                for (int i = 0; i < len; i++)
                {
                    if (can(i, ls[0]))
                        dp[0, i] = numbits(i);
                }

                for(int j = 1; j < M; j++)
                    for (int i = 0; i < len; i++)
                    {
                        if (can(i, ls[j]))
                        {
                            for (int k = 0; k < len; k++)
                                if (can1(i, k))
                                {
                                    dp[j, i] = Math.Max(dp[j, i], numbits(i) + dp[j - 1, k]);
                                }
                        }
                    }

                int result = 0;
                for (int i = 0; i < len; i++)
                    result = Math.Max(result, dp[M - 1, i]);

                
                sw.WriteLine("Case #" + (z + 1) + ": " + result);
            }
            sw.Close();
        }
    }
}
