using System;
using System.Linq;

class Program {
    public static void Main() {
        var s = string.Join("",
            Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse).OrderBy(f => f));
        Console.WriteLine(s.Equals("557") ? "YES" : "NO");
    }
}