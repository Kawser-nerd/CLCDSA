using System;
using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var num = ToInt32(input[0]);
        var fig = ToInt32(input[1]);
        var lengths = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        Array.Sort(lengths);
        var sum = 0;
        for(var i = 0; i < fig; i++)
        {
            sum += lengths[num - i - 1];
        }
        WriteLine(sum);
    }
}