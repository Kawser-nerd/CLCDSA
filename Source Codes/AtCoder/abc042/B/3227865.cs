using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var num = ToInt32(input[0]);
        var length = ToInt32(input[1]);
        var strs = new string[num];
        for(var i = 0; i < num; i++)
        {
            strs[i] = ReadLine();
        }
        Array.Sort(strs);
        for(var i = 0; i < num; i++)
        {
            Write(strs[i]);
        }
        WriteLine();
    }
}