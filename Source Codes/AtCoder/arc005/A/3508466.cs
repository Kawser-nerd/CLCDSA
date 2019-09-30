using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var s = ReadLine().Split(' ','.');
        var t = "Takahashikun";
        var T = "TAKAHASHIKUN";
        var ta = "takahashikun";
        WriteLine(
            s.Count(c => c == t || c == T || c == ta)
            );
            
    }
}