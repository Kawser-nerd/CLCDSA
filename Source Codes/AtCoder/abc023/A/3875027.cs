using System;
using System.Collections.Generic;
using System.Linq;
class Program {
    static void Main () {
        var input = Console.ReadLine ();

        var ten = int.Parse (input.Substring (0, 1));
        var one = int.Parse (input.Substring (1, 1));

        Console.WriteLine (ten + one);
    }
}