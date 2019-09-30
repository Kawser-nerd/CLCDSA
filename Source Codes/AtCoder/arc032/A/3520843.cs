using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        if (num == 1) { WriteLine("BOWWOW");return; }
        var s = num * (num + 1) / 2;
        for(var i = 2; i * i < s; i++)
            if (s % i == 0) { WriteLine("BOWWOW");return; }
        WriteLine("WANWAN");
    }
}