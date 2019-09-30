using System;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var height = input[0];
        var width = input[1];
        var strs = new string[height];
        for(var i = 0; i < height; i++)
        {
            strs[i] = ReadLine();
        }
        for(var i = 0; i < height; i++)
        {
            WriteLine($"{strs[i]}\n{strs[i]}");
        }
    }
}