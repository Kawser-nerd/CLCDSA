using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var town = new Dictionary<string, int>();

        var sum = 0;
        for(var i = 0; i < num; i++)
        {
            var input = ReadLine().Split(' ');
            town[input[0]] = ToInt32(input[1]);
            sum += ToInt32(input[1]);
        }

        try
        {
            WriteLine(town.First(t => t.Value > sum / 2).Key);
        }
        catch
        {
            WriteLine("atcoder");
        }
    }
}