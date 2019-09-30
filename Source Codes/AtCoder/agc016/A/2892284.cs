using System;
using System.IO;
using System.Diagnostics;
using System.Linq;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        char[] cs = s.Distinct().ToArray();
        int min = int.MaxValue;
        foreach (var c in cs)
        {
            char[] vs = s.ToArray();
            int count = 0;
            while (vs.Distinct().Count() != 1)
            {
                char[] newv = new char[vs.Length - 1];
                for (int i = 0; i < newv.Length; i++)
                {
                    if (vs[i] == c || vs[i + 1] == c) newv[i] = c;
                    else newv[i] = vs[i];
                }
                vs = newv;
                Debug.WriteLine(string.Join(" ",vs));
                count++;
            }
            min = Min(min, count);
        }
            Console.WriteLine(min);
    }
}