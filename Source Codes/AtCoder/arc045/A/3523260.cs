using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var st1=str.Replace("Left", "<");
        var st2=st1.Replace("Right", ">");
        var st3=st2.Replace("AtCoder", "A");
        WriteLine(st3);
    }
}