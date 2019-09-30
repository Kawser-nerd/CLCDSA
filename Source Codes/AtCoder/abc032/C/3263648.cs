using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var length = ToInt32(input[0]);
        var limit = ToInt32(input[1]);
        var seq = new int[length];
        var containZero = false;
        for(var i = 0; i < length; i++)
        {
            seq[i] = ToInt32(ReadLine());
            if (seq[i] == 0) containZero = true;
        }
        if (containZero) { WriteLine(length);return; }

        var result = 0;
        double p = 1;
        var ahead = 0;
        var end = 0;
        for(var i = 0; i < int.MaxValue; i++)
        {
            if (p * seq[ahead] <= limit)
            {
                p *= seq[ahead];
                if (result < ahead - end + 1) result = ahead - end + 1;
                ahead++;
            }
            else if (ahead > end) { p /= seq[end]; end++; }
            else { ahead++; end++; }
            if (ahead == length) break;
        }
        WriteLine(result);
    }
}