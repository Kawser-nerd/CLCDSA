using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var day = ToInt32(input[0]);
        var mi = ToInt32(input[1]);
        var times = new int[day];
        for (var i = 0; i < day; i++)
            times[i] = ToInt32(ReadLine());
        for(var i = 2; i < day; i++)
        {
            var sl = times[i - 2] + times[i - 1] + times[i];
            if (sl < mi) { WriteLine(i + 1);return; }
        }
        WriteLine(-1);
    }
}