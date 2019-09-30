using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var year = ToInt32(ReadLine());
        var month = ToInt32(ReadLine());
        if (month == 1 || month == 2) { year--; month += 12; }
        var day = ToInt32(ReadLine());
        const int DY= 735369;
        WriteLine(DY -
            (365 * year + year / 4 - year / 100 + year / 400
            + 306 * (month + 1) / 10 + day - 429));
    }
}