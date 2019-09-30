using System;

class Atcoder75
{
    public static void Main()
    {
        int x = int.Parse(Console.ReadLine());
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());

        int budget = x - a;
        Console.WriteLine(budget % b);
    }
}