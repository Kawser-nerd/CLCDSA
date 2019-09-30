using System;
using System.Linq;
class Program
{
    static void Main()
    {
        char input =char.Parse(Console.ReadLine());
        Console.WriteLine(input- char.Parse("A")+1);
        Console.ReadLine();
    }
}