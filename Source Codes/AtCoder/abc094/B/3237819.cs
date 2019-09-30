using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var toll = ToInt32(input[1]);
        var start = ToInt32(input[2]);
        var gate = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var result = 0;
        var resultNum = 0;
        for(var i = 0; i < toll; i++)
        {
            if (gate[i] <= start) result++;
            else resultNum++;
        }
        WriteLine(Math.Min(result, resultNum));
    }
}