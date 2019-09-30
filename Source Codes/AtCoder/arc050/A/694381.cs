using System;

public class Program
{
    public static void Main()
    {
        var C = Console.ReadLine().Split(' ');

        Console.WriteLine((C[0][0]- 'A') == (C[1][0] - 'a') ? "Yes" : "No" );
    }
}