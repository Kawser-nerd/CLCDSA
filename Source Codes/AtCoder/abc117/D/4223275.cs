using System;
using System.Linq;
using System.Collections.Generic;

class Dmondai
{
    static void Main()
    {
        var line = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
        var N = line[0];
        var K = line[1];
        var A = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
        if (K == 0)
        {
            Console.WriteLine(A.Sum(x=>x));
            return;
        }
        var length = (long)Math.Log(K, 2);
        var count = new int[length+1];
        var bit = 1L;
        for (int i=0;i<=length;++i)
        {
            for (long j = 0; j < N; ++j) if ((bit & A[j]) != 0) count[i]++;
            bit <<= 1;
        }
        bit = 1L;
        bit <<= (int)length;
        var num = 0L;
        var temp = 0L;
        for (long i=length;0<=i;--i)
        {
            if (count[i] < ((N+1) / 2) ) temp |= bit;
            if (temp <= K) num = temp;
            else temp = num;
            bit >>= 1;
        }
        var ans = 0L;
        for (int i = 0; i < N; ++i) ans += (num ^ A[i]);
        Console.WriteLine(ans);
    }
}