using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        for (var i = num; i > 0; i--)
        {
            if (Math.Sqrt(i) == (int)Math.Sqrt(i)) { WriteLine(i); break; }
        }
    }
}