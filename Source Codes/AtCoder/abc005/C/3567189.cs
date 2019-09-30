using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var time = ToInt32(ReadLine());
        var num = ToInt32(ReadLine());
        var tako = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var que = new Queue<int>();
        for (var i = 0; i < num; i++) que.Enqueue(tako[i]);
        var pe = ToInt32(ReadLine());
        var cus = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var isresult = true;
        for (var i = 0; i < pe; i++)
        {
            var isMatch = false;
            while (!isMatch)
            {
                if (que.Count == 0) break;
                var q = que.Dequeue();
                if (q > cus[i]) break;
                else if (cus[i] - q > time) continue;
                else isMatch = true;
            }
            if (!isMatch) { isresult = false;break; }
        }
        WriteLine(isresult?"yes":"no");
    }
}