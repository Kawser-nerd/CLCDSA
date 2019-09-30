using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var t = Console.ReadLine();
        for (int i = 0; i < s.Length; i++)
        {
            s = s[s.Length - 1] + s.Substring(0, s.Length - 1);

            if (s == t)
            {
                Console.WriteLine("Yes");
                return;
            }
        }
        Console.WriteLine("No");
    }
}