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
        var num = ToInt32(ReadLine());
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var l = 0;
        var r = 0;
        var result = 0L;
        while (l != num-1 || r != num-1)
        {
            if (l == r)
            {
                result++;
                r++;
            }
            else if (ar[r] > ar[r - 1] && r != num - 1)
            {
                result += r - l + 1;
                r++;
            }
            else if (ar[r] <= ar[r - 1])
                l = r;
            else
            {
                result += r - l + 1;
                break;
            }
        }
        WriteLine(ar[num-2]>=ar[num-1]?result+1:result);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}