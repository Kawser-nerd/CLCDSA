using System;
class Program
{
    public static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        long a, b, c;
        a = long.Parse(s[0]);
        b = long.Parse(s[1]);
        c = long.Parse(s[2]);
        long v;
        v = (a * b) % 1000000007;
        v = (v * c) % 1000000007;
        Console.WriteLine(v);
    }
}