using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Magatro
{
   
    static void Main()
    {
        long A, B, K, L;
        string[] s = Console.ReadLine().Split(' ');
        A = long.Parse(s[0]);
        B = long.Parse(s[1]);
        K = long.Parse(s[2]);
        L = long.Parse(s[3]);
        long set = K / L;
        long setm = set * B;
        long nokori = K % L;
        long nokorim = Math.Min(nokori * A, B);
        Console.WriteLine(setm + nokorim);
    }
   
}