using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        var s = Console.ReadLine().Split(' ');
        int A = int.Parse(s[0]);
        int B = int.Parse(s[1]);
        int C = int.Parse(s[2]);
        int ctr = 0;
        int i = Math.Min(B, C);
        ctr += 2 * i;
        B -= i;
        C -= i;
        i = Math.Min(A, C);
        ctr += i;
        A -= i;
        C -= i;
        ctr += B;
        if (C > 0)
            ctr++;
        Console.WriteLine(ctr);
    }
}