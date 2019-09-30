using System;

class Atcoder96
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        if (n % 2 == 0)
            Console.WriteLine((n / 2) * (n / 2));
        else
            Console.WriteLine(((n - 1) / 2) * ((n + 1) / 2));
    }
}