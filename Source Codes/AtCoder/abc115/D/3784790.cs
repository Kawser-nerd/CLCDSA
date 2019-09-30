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

        //????????
        var bArray = new long[N + 1];
        bArray[0] = 1;
        //?????
        var pArray = new long[N + 1];
        pArray[0] = 1;
        for (long i = 1; i <= N; ++i)
        {
            bArray[i] = bArray[i - 1] * 2 + 3;
            pArray[i] = pArray[i - 1] * 2 + 1;
        }

        var ans = 0L;
        var k = K;
        for (var i=N;-1<i;--i) {
            var num = (bArray[i] + 1) / 2;
            if (k <= i)
            {
                break;
            }
            else if ((num - 1) == k || (num - 2) == k)
            {
                ans += pArray[i - 1];
                break;
            } else if (num == k)
            {
                ans += pArray[i - 1] + 1;
                break;
            } else if (bArray[i] - i <= k)
            {
                ans += pArray[i];
                break;
            }
            else {
                if (num < k)
                {
                    ans += pArray[i - 1] + 1;
                    k -= num;
                }
                else
                {
                    --k;
                }
            }
        }
        Console.WriteLine(ans);
    }
}