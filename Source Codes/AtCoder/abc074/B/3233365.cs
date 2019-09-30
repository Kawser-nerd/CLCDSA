using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var ball = ToInt32(ReadLine());
        var num = ToInt32(ReadLine());
        var coordinates = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var result = 0;
        for(var i = 0; i < ball; i++)
        {
            if (coordinates[i] < num - coordinates[i]) result += coordinates[i];
            else result += num - coordinates[i];
        }
        WriteLine(result*2);
    }
}