using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Numerics;
 
class Program
{
    static void Main()
    {
        const int divisor = 1000000007;
        int n = int.Parse(Console.ReadLine());
        int[] A = Console.ReadLine().Split(' ')
                                .Select(elem => int.Parse(elem))
                                .OrderByDescending(elem => elem)
                                .ToArray();
        bool flag = true;
        int num = n - 1;
        for (int i = 0; i < A.Length; i++)
        {
            if(A[i] != num) {flag = false; break;}
            if(i % 2 != 0) num -= 2;
        }
        var numOfPattern = flag ? BigInteger.ModPow(2, n / 2, divisor) : 0;
        Console.WriteLine(numOfPattern);
    }
}