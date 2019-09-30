using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var N = Int32.Parse(Console.ReadLine());
        var A = Console.ReadLine().Split(' ').Select(x => Int32.Parse(x)).ToArray();
        var ans = 0L;
        for (int i=0;i<N;++i)
        {
            ans += A[i] - 1;
        }
        Console.WriteLine(ans);
    }
}