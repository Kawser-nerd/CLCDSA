using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().Split(' ');
        var a = int.Parse(s[0]);
        var b = int.Parse(s[1]);
        var c = int.Parse(s[2]);

        var ans = true;

        s = Console.ReadLine().Split(' ');
        var d = a - int.Parse(s[0]);
        var e = b - int.Parse(s[1]);
        var f = c - int.Parse(s[2]);
        ans &= d == e;
        ans &= e == f;

        s = Console.ReadLine().Split(' ');
        d = a - int.Parse(s[0]);
        e = b - int.Parse(s[1]);
        f = c - int.Parse(s[2]);
        ans &= d == e;
        ans &= e == f;

        Console.WriteLine(ans ? "Yes" : "No");
    }
}