using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int a, d;
        a = int.Parse(str[0]);
        d = int.Parse(str[1]);
        Console.WriteLine(Math.Max((a + 1) * d, (d + 1) * a));
    }
}