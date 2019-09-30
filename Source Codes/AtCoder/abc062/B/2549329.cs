using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var hw = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var hor = string.Join("", Enumerable.Repeat("#", hw[1] + 2));
        var vert = "#";
        Console.WriteLine(hor);
        for (int i = 0; i < hw[0]; i++) Console.WriteLine(vert + Console.ReadLine() + vert);
        Console.WriteLine(hor);
    }
}