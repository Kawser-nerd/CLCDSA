using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Magatro
{
    const long nityou = 2000000000000;
    static void Main()
    {
        long A;
            int K;
        string[] s = Console.ReadLine().Split(' ');
        A = long.Parse(s[0]);
        K = int.Parse(s[1]);
        if (K == 0)
        {
            Console.WriteLine(nityou - A);
            return;
        }
        int cnt = 0;
        while (A < nityou)
        {
            A += 1 + A * K;
            cnt++;
        }
        Console.WriteLine(cnt);
    }
   
}