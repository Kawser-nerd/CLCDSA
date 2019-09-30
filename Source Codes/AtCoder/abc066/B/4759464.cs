using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        for (int i = s.Length - 1; i >= 0; i--)
        {
            if (m1(s.Substring(0, i)))
            {
                Console.WriteLine(i);
                return;
            }
        }
    }

    static bool m1(string s)
    {
        return s.Substring(s.Length / 2) == s.Substring(0, s.Length / 2);
    }
}