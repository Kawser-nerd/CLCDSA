using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int h1, h2, w1, w2;
        h1 = int.Parse(str[0]);
        w1 = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        h2 = int.Parse(str[0]);
        w2 = int.Parse(str[1]);
        bool f = (h1 == h2) || (h1 == w2) || (w1 == h2) || (w1 == w2);
        Console.WriteLine(f ? "YES" : "NO");
    }
}