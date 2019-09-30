using System;
using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var city = ToInt32(input[0]);
        var road = ToInt32(input[1]);
        var counter = new int[city];
        for(var i = 0; i < road; i++)
        {
            var input2 = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            counter[input2[0] - 1]++;
            counter[input2[1] - 1]++;
        }

        foreach(var val in counter)
        {
            WriteLine(val);
        }
    }
}