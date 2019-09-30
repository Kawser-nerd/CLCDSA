using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var min = int.MaxValue;
        for(var i = 1; i <= num / 2; i++)
        {
            var a = i.ToString();
            var b = (num - i).ToString();
            var d1 = 0;
            var d2 = 0;
            for (var j = 0; j < a.Length; j++)
                d1 += ToInt32(a.Substring(j,1));
            for (var j = 0; j < b.Length; j++)
                d2 += ToInt32(b.Substring(j,1));
            min = Min(min, d1 + d2);
        }
        WriteLine(min);
    }
}