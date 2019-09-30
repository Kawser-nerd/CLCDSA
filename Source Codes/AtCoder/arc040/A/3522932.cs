using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var t = 0;
        var a = 0;
        for (var i = 0; i < num; i++)
        {
            var s = ReadLine();
            t += s.Count(c => c == 'R');
            a += s.Count(c => c == 'B');
        }
        WriteLine(t == a ? "DRAW" : t > a ? "TAKAHASHI" : "AOKI");
    }
}