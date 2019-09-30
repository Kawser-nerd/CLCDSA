using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        if (num < 10) { WriteLine(num); return; }
        var r = "";
        for (var i = 0; i <= (num-1) / 9; i++)
            r += "1";
        WriteLine(num%9!=0?ToInt32(r) * (num%9):ToInt32(r)*9);
    }
}