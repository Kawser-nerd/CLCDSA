using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

public class Program
{
    public static void Main()
    {
        var n = int.Parse(ReadLine());

        var previous = 2L;
        var current = 1L;
        var l = 0L;
        if (n == 0) l = previous;
        else if (n == 1) l = current;
        else
        {
            for (var i = 2L; i <= n; i++)
            {
                l = previous + current;
                previous = current;
                current = l;
            }
        }

        WriteLine(l);
    }
}