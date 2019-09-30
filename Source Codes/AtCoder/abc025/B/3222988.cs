using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var num = ToInt32(input[0]);
        var min = ToInt32(input[1]);
        var max = ToInt32(input[2]);
        var result = 0;
        for(var i = 0; i < num; i++)
        {
            var input2 = ReadLine().Split(' ');
            var s = input2[0]=="East"?1:-1;
            var fig = ToInt32(input2[1]);
            if (fig <= min) result += s * min;
            else if (fig >= max) result += s * max;
            else result += s * fig;
        }

        if (result == 0) WriteLine(0);
        else if (result > 0) WriteLine($"East {result}");
        else WriteLine($"West {Math.Abs(result)}");
    }
}