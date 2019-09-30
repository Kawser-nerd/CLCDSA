using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var mon = ToUInt64(input[0]);
        var slo = ToUInt64(input[1]);
        var li = 2000000000000UL;
        var result = 0L;
        if (slo == 0) { WriteLine(li - mon); return; }
        while (mon < li)
        {
            mon += 1 + slo * mon;
            result++;
        }
        WriteLine(result);
    }
}