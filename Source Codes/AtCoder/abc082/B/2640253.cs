using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main(string[] args) {
        var s = ReadLine();
        var t = ReadLine();

        if (String.Compare(new String(s.ToCharArray().OrderBy(str => str).ToArray()),
                           new string(t.ToCharArray().OrderBy(str => -str).ToArray())) < 0) {
            WriteLine("Yes");
        } else {
            WriteLine("No");
        }
    }
}