using System;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var s = Console.ReadLine();
        var t = Console.ReadLine();

        for (var i = 0; i < s.Length; i++)
        {
            s = s.Substring(1, s.Length - 1) + s.Substring(0, 1);

            if (s == t)
            {
                Console.WriteLine("Yes");
                return;
            }
        }

        Console.WriteLine("No");
    }
}