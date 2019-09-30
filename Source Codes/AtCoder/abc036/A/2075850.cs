using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int a, b;
        a = int.Parse(str[0]);
        b = int.Parse(str[1]);
        int c = (b % a == 0) ? 0 : 1;
        c += b / a;
        Console.WriteLine(c);
    }
}