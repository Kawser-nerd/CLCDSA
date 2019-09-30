using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        for (int i = 1; i < s.Length; i++)
        {
            string t =  s.Substring(0, s.Length - i);
            if (t.Length % 2 != 0) continue;
            if (t.Substring(0, t.Length / 2) != t.Substring(t.Length / 2)) continue;
            Console.WriteLine(t.Length);
            return;
        }
    }
}