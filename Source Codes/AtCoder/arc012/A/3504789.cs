using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var day = ReadLine();
        var array = new[] { "Sunday", "Friday", "Thursday", "Wednesday", "Tuesday", "Monday", "Saturday" };
        for (var i = 0; i < 7; i++) if (day == array[i]) { WriteLine(i % 6); return; }
    }
}