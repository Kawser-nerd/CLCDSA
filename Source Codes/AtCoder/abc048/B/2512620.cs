using System;

class B {
    public static void Main() {
        var line = Console.ReadLine().Split();
        var a = long.Parse(line[0]);
        var b = long.Parse(line[1]);
        var x = long.Parse(line[2]);
        Func<long, long> f = c => c < 0 ? 0 : c / x + 1;
        Console.WriteLine(f(b) - f(a - 1));
    }
}