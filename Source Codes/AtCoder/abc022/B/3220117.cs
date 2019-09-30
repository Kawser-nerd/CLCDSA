using System.Collections.Generic;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var flowers = new HashSet<int>();
        var result = 0;
        for(var i = 0; i < num; i++)
        {
            var fig = ToInt32(ReadLine());
            if (flowers.Contains(fig)) result++;
            flowers.Add(fig);
        }
        WriteLine(result);
    }
}