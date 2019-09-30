using System;
using System.IO;
using System.Linq;
using System.Runtime;
using System.Reflection;
using System.Diagnostics;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.RegularExpressions;
using static System.Math;


class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int min = int.MaxValue;
        int score = 0;
        for (int i = 0; i < n; i++)
        {
            int s = int.Parse(Console.ReadLine());
            score += s;
            if (s % 10 != 0) min = Min(min, s);
        }
        Console.WriteLine(score % 10 != 0 ? score : Max(0, score - min));
    }
}