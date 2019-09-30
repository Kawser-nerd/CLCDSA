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
        var nm = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var xy = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var a = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var b = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var quea = new Queue<int>();
        var queb = new Queue<int>();
        for (var i = 0; i < nm[0]; i++)
            quea.Enqueue(a[i]);
        for (var j = 0; j < nm[1]; j++)
            queb.Enqueue(b[j]);
        var now = 0;
        var result = 0L;
        var isA = true;
        while (quea.Count != 0 || queb.Count != 0)
        {
            var time = 0;
            if (isA)
            {
                if (quea.Count == 0) break;
                time = quea.Dequeue();
            }
            else
            {
                if (queb.Count == 0) break;
                time = queb.Dequeue();
            }
            if (time >= now)
            {
                if (!isA) result++;
                isA = !isA;
                now = time + xy[ToInt32(isA)];
            }
        }
        WriteLine(result);
            
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}