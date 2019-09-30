using System;
using System.Collections.Generic;

public class Program
{
    static void Main()
    {
        var str = Console.ReadLine();
        var count = 0;
        var buf = str[0];
        for (int i = 1; i < str.Length; i++)
        {
            if (buf != str[i])
            {
                buf = str[i];
                count++;
            }
        }

        Console.WriteLine(count);
    }
}