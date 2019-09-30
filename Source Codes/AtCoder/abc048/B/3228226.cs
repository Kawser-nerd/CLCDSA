using System;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var input = Array.ConvertAll(ReadLine().Split(' '), ulong.Parse);
        var min = input[0];
        var max = input[1];
        var num = input[2];
        ulong result = 0;
        if (min != 0) result = max / num - (min-1) / num;
        else result = max / num + 1;
        WriteLine(result);

    }
}