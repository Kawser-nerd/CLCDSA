using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var st = ToInt32(input[0]);
        var go = ToInt32(input[1]);
        if (Sign(st) == Sign(go)) WriteLine(Abs(go - st));
        else WriteLine(Abs(go - st)-1);
    }
}