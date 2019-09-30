using System.Collections.Generic;
using static System.Console;

class Atcoder
{
    public static void Main()
    {
        var d = new Dictionary<string, string>()
        {{"A", "T"}, {"T", "A"}, {"C", "G"}, {"G", "C"}};
        WriteLine(d[ReadLine()]);
    }
}