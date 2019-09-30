using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var blue = ToInt32(ReadLine());
        var p = new Dictionary<string, int>();
        for(var i = 0; i < blue; i++)
        {
            var str = ReadLine();
            if (p.ContainsKey(str)) p[str]++;
            else p[str] = 1;
        }
        var red = ToInt32(ReadLine());
        for(var i = 0; i < red; i++)
        {
            var str= ReadLine();
            if (p.ContainsKey(str)) p[str]--;
            else p[str] = -1;
        }
        var max = p.Values.Max();
        if (max < 0) WriteLine(0);
        else WriteLine(max);

    }
}