using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int a, b;
        a = int.Parse(str[0]);
        b = int.Parse(str[1]);
        bool f = 3 * a == 4 * b;
        Console.WriteLine(f ? "4:3" : "16:9");
    }
}