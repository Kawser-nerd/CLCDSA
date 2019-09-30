using System;

class Atcoder89
{
    public static void Main()
    {
        string s = Console.ReadLine();

        int length = s.Length;
        int pluscount = length - s.Replace("+", "").Length;

        int value = pluscount * 1 + (length - pluscount) * (-1);
        Console.WriteLine(value);
    }
}