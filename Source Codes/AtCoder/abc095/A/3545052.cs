using System;

class Atcoder83
{
    public static void Main()
    {
        string s = Console.ReadLine();
        int addition = CountChar(s, 'o');

        Console.WriteLine(700 + addition * 100);
    }

    public static int CountChar(string s, char c)
    {
        int countif = s.Length - s.Replace(c.ToString(), "").Length;
        return countif;
    }
}