using System;
using System.Linq;

class Program {
    static void Main(string[] args) {
        var a = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        Array.Sort(a);
        Console.WriteLine(a[0] * a[1] * a[2] % 2 * a[0] * a[1]);
    }
}