using System;

class Atocder46
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int reward = n / 15;

        Console.WriteLine(800 * n - 200 * reward);
    }
}