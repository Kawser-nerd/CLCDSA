using System;

class Program
{
    static void Main(string[] args)
    {
        int y = int.Parse(Console.ReadLine());
        int m = int.Parse(Console.ReadLine());
        int d = int.Parse(Console.ReadLine());
        if (m == 1) { y--; m = 13; }
        if (m == 2) { y--; m = 14; }
        long ans = 365 * y + (y / 4) - (y / 100) + (y / 400) + ((306 * m + 306) / 10) + d - 429;
        Console.WriteLine(735369 - ans);
        Console.ReadLine();
    }
}