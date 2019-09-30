using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var t = Console.ReadLine();

        for (int i = 0; i < 3; i++)
        {
            if (s[i] != t[2 - i])
            {
                Console.WriteLine("NO");
                return;
            }
        }

        Console.WriteLine("YES");
    }
}