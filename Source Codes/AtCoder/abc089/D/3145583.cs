using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;
using static System.Math;

class Program
{
    struct Point {
        public int X;
        public int Y;
    }

    static void Main(string[] args)
    {
        label:
        var sp = ReadLine().Split();
        int h = Parse(sp[0]);
        int w = Parse(sp[1]);
        int d = Parse(sp[2]);
        var array = new Point[h * w + 1];
        for(int row = 0; row < h; ++row)
        {
            sp = ReadLine().Split();
            for(int col = 0; col < sp.Length; ++col)
            {
                int num = Parse(sp[col]);
                array[num].X = col;
                array[num].Y = row;
            }
        }
        var mpArray = new int[array.Length];
        for(int i = 0; i < mpArray.Length; ++i)
        {
            if (i <= d) continue;
            mpArray[i] = mpArray[i - d] + Abs(array[i].X - array[i - d].X) + Abs(array[i].Y - array[i - d].Y);
        }
        var results = new int[Parse(ReadLine())];
        for(int i = 0; i < results.Length; ++i)
        {
            sp = ReadLine().Split();
            results[i] = mpArray[Parse(sp[1])] - mpArray[Parse(sp[0])];
        }
        foreach(int n in results)
        {
            WriteLine(n);
        }
        //goto label;
    }
}