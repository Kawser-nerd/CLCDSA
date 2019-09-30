using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        for (int i = 0; i < s.Length; i++)
        {
            Console.Write(s[i] == '9' ? '1' : '9');
        }
        Console.WriteLine();
    }
}