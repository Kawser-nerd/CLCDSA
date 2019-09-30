using System.Collections.Generic;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var counter = new Dictionary<string, int>()
        {
            ["A"] = 0,
            ["B"] = 0,
            ["C"] = 0,
            ["D"] = 0,
            ["E"] = 0,
            ["F"] = 0
        };

        for(var i = 0; i < str.Length; i++)
        {
            var chara = str.Substring(i, 1);
            counter[chara]++;
        }
        WriteLine($"{counter["A"]} {counter["B"]} {counter["C"]} {counter["D"]} {counter["E"]} {counter["F"]}");
    }
}