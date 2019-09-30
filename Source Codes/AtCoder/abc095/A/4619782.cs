using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();

        var ans = 700;
        if (s[0] == 'o') ans += 100;
        if (s[1] == 'o') ans += 100;
        if (s[2] == 'o') ans += 100;
        Console.WriteLine(ans);
    }
}