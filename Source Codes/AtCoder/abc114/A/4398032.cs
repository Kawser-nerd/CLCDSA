using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;


class Program
{

    static void Main(string[] Args) {
        var X = Int32.Parse(ReadLine());
        if (X == 3 || X == 5 || X == 7) {
            WriteLine("YES");
            return;
        }
        WriteLine("NO");

        ReadLine();
    }
}