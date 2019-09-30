using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int a, b;
        a = int.Parse(str[0]);
        b = int.Parse(str[1]);
        bool f = a < b;
        Console.WriteLine(f ? "Better" : "Worse");
    }
}