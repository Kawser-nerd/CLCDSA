using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

class Program {
    static void Main(string[] args) {
        var a = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).OrderBy(x => x).ToArray();
        Console.WriteLine(a[0] * a[1] * a[2] % 2 * a[0] * a[1]);
    }
}