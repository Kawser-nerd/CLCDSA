using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using static System.Math;


class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        HashSet<string> set = new HashSet<string>();
        var s = Console.ReadLine();
        set.Add(s);
        char lastChar = s.Last();
        for (int i = 0; i < n - 1; i++)
        {
            s = Console.ReadLine();
            if(!set.Add(s) || s.First() != lastChar)
            {
                Console.WriteLine("No");
                return;
            }
            lastChar = s.Last();
        }
        Console.WriteLine("Yes");
    }
}