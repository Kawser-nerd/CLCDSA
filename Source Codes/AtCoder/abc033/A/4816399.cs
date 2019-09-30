using System;
using System.Linq;
class Program
{
    static void Main()
    {
        char[] input = Console.ReadLine().ToCharArray();
        Console.WriteLine(input.Distinct().ToArray().Length==1?"SAME": "DIFFERENT");
        Console.ReadLine();
    }
}