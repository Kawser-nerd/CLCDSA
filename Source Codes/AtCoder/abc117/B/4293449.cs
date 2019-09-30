using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        ReadLine();
        var L = new List<string>(ReadLine().Split(' ')).Select(ele => Int32.Parse(ele)).ToList();
        var max = L.Max();
        L.Remove(max);
        if (L.Sum() > max)
            WriteLine("Yes");
        else
            WriteLine("No");

        Console.ReadLine();
    }
}