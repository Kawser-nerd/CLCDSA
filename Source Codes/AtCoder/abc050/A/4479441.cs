using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;


class Program
{
    static void Main(string[] Args) {
        var lis = new List<string>(ReadLine().Split(' '));
        int A = Int32.Parse(lis[0]);
        int B = Int32.Parse(lis[2]);
        if (lis[1] == "-") B *= -1;

        WriteLine(A + B);

        ReadLine();
    }
}