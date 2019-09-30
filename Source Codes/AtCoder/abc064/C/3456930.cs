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
        var rates = Array.ConvertAll(ReadLine().Split(' '),int.Parse);
        var bet = new[] { 399, 799, 1199, 1599, 1999, 2399, 2799, 3199 };
        var set = new HashSet<int>();
        var counter = 0;
        for (var i = 0; i < num; i++)
        {
            var index = Search.LowerBound(bet, rates[i]);
            if (index >= bet.Length) counter++;
            else set.Add(index);
        }
        WriteLine($"{Max(1,set.Count)} {set.Count + counter}");
    }
}

public class Search
{
  public static int LowerBound(int[] array, int value)
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid] >= value) high = mid;
            else low = mid + 1;
        }
        return low;
    }
}