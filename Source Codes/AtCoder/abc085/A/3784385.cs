using System;

class Program
{
    static void Main()
    {
        char[] c = Console.ReadLine().ToCharArray();
        c[3] = '8';
        Console.WriteLine(new string(c));
    }
}