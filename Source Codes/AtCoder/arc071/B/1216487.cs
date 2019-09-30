using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Numerics;

class p
{

    static void Main(string[] args)
    {
        //????????
        //??????????????????????????
        //BItemp?BigInteger??????????BigInteger????????Long???????
        long Xsum = 0;
        long Ysum = 0;
        long BItemp;

        string[] input = Console.ReadLine().Split();
        long N = long.Parse(input[0]);
        long M = long.Parse(input[1]);

        long Q = 1000000007;

        string[] inputX = Console.ReadLine().Split();

        for(long i = 0; i < N; i++)
        {
            BItemp = long.Parse(inputX[i]);
            Xsum += i * BItemp - (N - (i + 1)) * BItemp;
            Xsum %= Q;
        }

        string[] inputY = Console.ReadLine().Split();

        for (long i = 0; i < M; i++)
        {
            BItemp = long.Parse(inputY[i]);
            Ysum += i * BItemp - (M - (i + 1)) * BItemp;
            Ysum %= Q;
        }

        long ans = (Xsum * Ysum) % Q;
        Console.WriteLine(ans);
    }   
}