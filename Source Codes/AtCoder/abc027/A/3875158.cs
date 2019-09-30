using System;
using System.Collections.Generic;
using System.Linq;
class Program {
    static void Main () {
        var input = Console.ReadLine ().Split (' ').Select (x => int.Parse (x)).ToList ();
        if (input[0] == input[1]) {
            Console.WriteLine (input[2]);
            return;
        }
        if (input[1] == input[2]) {
            Console.WriteLine (input[0]);
            return;
        }
        if (input[2] == input[0]) {
            Console.WriteLine (input[1]);
            return;
        }
    }
}