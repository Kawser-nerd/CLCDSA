using System;

public class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        if (n % 2 == 0)
        {
            Console.WriteLine(n);
        }
        else
        {
            Console.WriteLine(n * 2);
        }
    }
}