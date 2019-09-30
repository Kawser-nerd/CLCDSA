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
        var degs = new[] { 0.0,112.5, 337.5, 562.5, 787.5, 1012.5, 1237.5, 1462.5, 1687.5, 1912.5, 2137.5, 2362.5, 2587.5, 2812.5, 3037.5, 3262.5, 3487.5 };
        var h = new[] { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N" };
        var diss = new[] { 0.0, 0.3, 1.6, 3.4, 5.5, 8.0, 10.8, 13.9, 17.2, 20.8, 24.5, 28.5, 32.7 };
        var degdis = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var di = Search.UpperBound(diss, Round((double)degdis[1]/6,MidpointRounding.AwayFromZero)/10)-1;
        var de = h[Search.UpperBound(degs, degdis[0])-1];
        WriteLine(di!=0?$"{de} {di}":"C 0");
    }
}

public class Search
{
  public static int UpperBound(double[] array,double value)
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid] > value) high = mid;
            else low = mid + 1;
        }
        return low;
    }
}