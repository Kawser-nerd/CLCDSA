using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var times = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var drinkFig = ToInt32(ReadLine());
        var result = new int[drinkFig];
        for(var i = 0; i < drinkFig; i++)
        {
            var input = ReadLine().Split(' ');
            var sum = 0;
            for (var j = 0; j < times.Length; j++)
            {
                if (j == ToInt32(input[0])-1) { sum += ToInt32(input[1]);continue; }
                sum += times[j];
            }
            result[i] = sum;
        }
        foreach(var val in result)
        {
            WriteLine(val);
        }
    }
    
}