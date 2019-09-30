using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

class Program
{
    static int f(int x) {
        if (x % 2 == 0) return x / 2;
        return 3 * x + 1;
    }

    static void Main(string[] args) {
        var list = new List<string>(Console.ReadLine().Split(' ')).Select(ele => Int32.Parse(ele)).ToList();

        Console.WriteLine(list[0] * list[1] / 2.0);


        Console.ReadLine();
    }
}