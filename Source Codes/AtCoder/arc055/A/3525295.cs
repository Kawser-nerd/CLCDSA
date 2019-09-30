using System.Numerics;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        BigInteger r = 1;
        for(var i = 0; i < num; i++)
            r *= 10;
        WriteLine(r + 7);
    }
}