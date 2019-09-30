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
        var ab = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var result = 0;
        while (ab[0] != ab[1])
        {
            var dif = Abs(ab[0] - ab[1]);
            if (dif >= 10) { result++; ab[0] = ab[0] > ab[1] ? ab[0] - 10 : ab[0] + 10; }
            else if (dif > 7)
            {
                result += ab[0] > ab[1] ? 1 + Abs(ab[1] - ab[0] + 10) :
                    1 + Abs(ab[1] - ab[0] - 10);
                ab[0] = ab[1];
            }
            else if (dif > 3)
            {
                result += ab[0] > ab[1] ? 1 + Abs(ab[1] - ab[0] + 5) :
                    1 + Abs(ab[1] - ab[0] - 5);
                ab[0] = ab[1];
            }
            else { result += dif; ab[0] = ab[1]; }
        }
        WriteLine(result);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}