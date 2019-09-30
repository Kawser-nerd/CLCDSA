using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using Debug = System.Diagnostics.Debug;


class Ph
{
    static void Main()
    {
        var b = Enumerable.Repeat(0, int.Parse(Console.ReadLine())).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        List<int> streaks = new List<int>();
        int currentColor = b.First();
        int currentCount = 0;
        for (int i = 0; i < b.Length; i++)
        {
            if(currentColor != b[i])
            {
                streaks.Add(currentCount);
                currentCount = 0;
            }
            currentCount++;
            currentColor = b[i];
        }
        if(streaks.Count == 0)
        {
            Console.WriteLine(-1);
            return;
        }
        if(b.First() == currentColor)
        {
            streaks[0] += currentCount;
        }
        Console.WriteLine((streaks.Max() + 1) / 2);
    }
}