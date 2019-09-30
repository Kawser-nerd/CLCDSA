using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    class P
    {
        public double x;
        public double y;
        public P(int x,int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var result = 0d;
        var p = new P[num];
        for(var i = 0; i < num; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            p[i] = new P(input[0],input[1]);
        }
        for(var i = 0; i < num; i++)
            for(var j = i+1; j < num; j++)
            {
                var d = 
                    Sqrt(Pow(p[i].x - p[j].x, 2) 
                    + Pow(p[i].y - p[j].y, 2));
                if (d > result) result = d;
            }
        WriteLine(result);
    }
}