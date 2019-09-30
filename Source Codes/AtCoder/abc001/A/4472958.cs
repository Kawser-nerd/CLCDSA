using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;


class Program
{
    static void Main(string[] Args) {
        int a = Int32.Parse(ReadLine());
        int b = Int32.Parse(ReadLine());

        WriteLine(a - b);

        ReadLine();
    }
}