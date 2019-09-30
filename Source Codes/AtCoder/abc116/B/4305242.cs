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
        var s = Int32.Parse(Console.ReadLine());
        var Numlist = new List<int>();
        Numlist.Add(s);

        int Result;
        for(Result = 2; ;Result++) {
            int tmp = f(Numlist.Last());
            if (Numlist.Contains(tmp))
                break;
            Numlist.Add(tmp);
        }

        Console.WriteLine(Result);
               
        Console.ReadLine();
    }
}