using System;

class Program
{
    static void Main(string[] args)
    {
        var nameA = Console.ReadLine();
        var nameB = Console.ReadLine();

        var str = nameA.Length > nameB.Length ? nameA : nameB;
        Console.WriteLine(str);
    }
}