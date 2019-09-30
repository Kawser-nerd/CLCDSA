using System;

class A
{
    static void Main()
    {
        var input = Console.ReadLine();
        var c = input.ToCharArray();

        Console.WriteLine(c[0] - 'A' + 1);
    }
}