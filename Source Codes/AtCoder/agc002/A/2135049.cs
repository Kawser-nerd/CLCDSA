using System;
using System.Linq;

class Program {
    static void Main(string[] args) {
        var a = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        if (a[0] <= 0 && a[1] >= 0) Console.WriteLine("Zero");
        else if (a[0] > 0) Console.WriteLine("Positive");
        else if (a[1] < 0) {
            Console.WriteLine((a[0] + a[1] + 1) % 2 == 0 ? "Positive" : "Negative");
        }
    }
}