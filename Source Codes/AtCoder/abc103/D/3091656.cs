using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;

class Program
{
    static void Main(string[] args)
    {
        var sp = ReadLine().Split();
        int count = Parse(sp[1]);
        var leftRight = new SortedList<int, int>(count);
        for (int i = 0; i < count; ++i)
        {
            sp = ReadLine().Split();
            int left = Parse(sp[0]);
            int right = Parse(sp[1]);
            if (!leftRight.ContainsKey(left) || right < leftRight[left])
            {
                leftRight[left] = right;
            }
        }
        int minRemoved = MaxValue;
        int result = 0;
        var keys = leftRight.Keys.ToArray();
        for (int i = keys.Length - 1; 0 <= i; --i)
        {
            var left = keys[i];
            var right = leftRight[left];
            if (right <= minRemoved)
            {
                ++result;
                minRemoved = left;
            }
        }
        WriteLine(result);
    }
}