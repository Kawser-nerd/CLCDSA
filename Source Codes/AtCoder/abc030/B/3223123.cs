using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var hour = ToDouble(input[0])%12;
        var minute = ToDouble(input[1]);

        hour = (hour+minute/60)*30;
        minute *= 6;
        var result = Math.Abs(hour - minute) < 360-Math.Abs(hour - minute) ? Math.Abs(hour - minute) : 360-Math.Abs(hour - minute);
        WriteLine(result);
    }
}