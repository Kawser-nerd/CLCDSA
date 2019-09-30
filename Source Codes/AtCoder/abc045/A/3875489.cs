using System;
using System.Collections.Generic;
using System.Linq;
class Program {
    static void Main () {
        var a = int.Parse (Console.ReadLine ());
        var b = int.Parse (Console.ReadLine ());
        var h = int.Parse (Console.ReadLine ());

        Console.WriteLine((a + b) * h / 2.0);
    }
}