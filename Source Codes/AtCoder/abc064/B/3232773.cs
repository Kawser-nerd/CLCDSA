using System;
using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var coordinate = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        Array.Sort(coordinate);
        WriteLine(coordinate[num - 1] - coordinate[0]);
    }
}