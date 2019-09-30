using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int x, a, b;
        x = int.Parse(str[0]);
        a = int.Parse(str[1]);
        b = int.Parse(str[2]);
        int da, db;
        da = Math.Max(a - x, x - a);
        db = Math.Max(b - x, x - b);
        Console.WriteLine((da < db) ? "A" : "B");
    }
}