using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var k = ToInt32(ReadLine());
        WriteLine(k <= Ceiling((double)(num - 1) / 2)?"YES":"NO");
    }
}