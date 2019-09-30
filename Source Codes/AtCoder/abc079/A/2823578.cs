using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Program {
    internal static void Main(string[] args) {
        var N = ReadLine().ToCharArray();
        if ((N[0] == N[1] && N[1] == N[2]) ||
            N[1] == N[2] && N[2] == N[3]) {
            WriteLine("Yes");
        } else {
            WriteLine("No");
        }
     }
}