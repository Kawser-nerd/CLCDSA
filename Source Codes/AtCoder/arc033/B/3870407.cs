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
        var ar1 = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ar2 = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        Array.Sort(ar2);
        var count = 0;
        for (var i = 0; i < ab[0]; i++)
            if (bina(ar2, ar1[i])) count++;
        WriteLine((double)count / ((long)ab[0]+ab[1] - count));
    }
    private static bool bina(int[] ar,int val)
    {
        var right = ar.Length;
        var left = 0;
        while (right > left)
        {
            var mid = (right + left) / 2;
            if (ar[mid] == val) { left = mid; break; }
            else if (ar[mid] > val) right = mid;
            else left = mid + 1;
        }
        try
        {
            return ar[left] == val;
        }
        catch
        {
            return false;
        }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}