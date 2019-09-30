using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var dif = ToInt32(input[0]);
        if (ToInt32(input[1]) == 100) WriteLine(Math.Pow(100, dif) * ToInt32(input[1]) + Math.Pow(100, dif));
        else WriteLine(Math.Pow(100,dif) * ToInt32(input[1]));
    }
}