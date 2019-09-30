using System;

class Program
{
    static void Main()
    {
        char[] s = Console.ReadLine().ToCharArray();
        s[3] = '8';
        foreach (var item in s)
        {
            Console.Write(item);
        }
        Console.Write("\n");
    }
}