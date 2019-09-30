using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var A = ReadLine().Split().Select(long.Parse).ToArray();
        WriteLine(A[0] * A[1] % (int)(1e9 + 7) * A[2] % (int)(1e9 + 7));
    }
}