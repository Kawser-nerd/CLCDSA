using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;


class B
{
    static bool[] isPrime;
    static int numSet = 0;
    static void Main(string[] args)
    {
        isPrime = NotPrimeArray();
        StreamReader sr = new StreamReader(args[0]);
        long cases = long.Parse(sr.ReadLine().Trim());
        
        for (long cas = 1; cas <= cases; cas++)
        {
            int[] asked = ToIntArr(sr.ReadLine().Trim().Split(new char[] { ' ' }));
            int start = asked[0];
            int end = asked[1];
            int prime = asked[2];
            int len = end + 1 - start;
            int[] arr = new int[len];
            for (int i = 0; i < len; i++)
                arr[i] = i;
            numSet = len;
            
            for (int k = prime; k <= end; k++)
            {
                if (IsPrime(k))
                {
                    for (int s = start; s <= end; s++)
                    {
                        for (int t = start; t <= end; t++)
                        {
                            if (s != t)
                            {
                                if (s % k == 0 && t % k == 0)
                                {
                                    MakeOneSet(arr, start, end, arr[s-start], arr[t-start]);
                                }
                            }
                        }
                    }
                }
            }

            Console.WriteLine("Case #" + cas + ": "+numSet);

        }
    }

    static void MakeOneSet(int[] arr, int start, int end, int a, int b)
    {
        if (a == b)
            return;
        int min = Math.Min(a,b);
        int max = Math.Max(a,b);
        for (int i = start; i <= end; i++)
        {
            if (arr[i-start] == max)
                arr[i-start] = min;
        }
        numSet--;
    }



    static int[] ToIntArr(string[] arg)
    {
        int[] ret = new int[arg.Length];
        for (int i = 0; i < arg.Length; i++)
            ret[i] = int.Parse(arg[i]);
        return ret;
    }

    static bool IsPrime(int arg)
    {
        return isPrime[arg];
    }

    static bool [] NotPrimeArray()
    {
        bool[] ret = new bool[1001];
        for(int i=0;i<ret.Length;i++)
            ret[i] = true;
        ret[0] = false;
        ret[1] = false;
        
        for (int i = 2; i < 40; i++)
        {
            for (int j = 2; j < 1000; j++)
            {
                if (i * j < ret.Length)
                    ret[i * j] = false;
            }
        }
        return ret;
    }
}

