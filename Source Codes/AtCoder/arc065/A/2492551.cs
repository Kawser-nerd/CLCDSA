using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        string s = string.Join("", Console.ReadLine().Reverse());
        string[] key = new string[] { "dream", "dreamer", "erase", "eraser" }.Select(x => string.Join("", x.Reverse())).ToArray();
        int index = 0;

        while (true)
        {
            if (s.Length == index) break;
            if (s.Length < index + 5) goto end;
            string ss = s.Substring(index, 5);
            if (ss == key[0] || ss == key[2])
            {
                index += 5;
                continue;
            }
            if (s.Length < index + 6) goto end;
            ss = s.Substring(index, 6);
            if (ss == key[3])
            {
                index += 6;
                continue;
            }
            if (s.Length < index + 7) goto end;
            ss = s.Substring(index, 7);
            if (ss == key[1])
            {
                index += 7;
                continue;
            }
            end:;
            Console.WriteLine("NO");
            return;
        }
        Console.WriteLine("YES");
    }
}