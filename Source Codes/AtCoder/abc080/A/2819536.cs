using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Program {
    internal static void Main(string[] args) {
        var inp = ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();

        WriteLine(Math.Min(inp[0] * inp[1], inp[2]));
    }
}