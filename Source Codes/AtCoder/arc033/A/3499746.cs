using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var s = ToInt32(ReadLine());
        WriteLine((s * s + s) / 2);
    }
}