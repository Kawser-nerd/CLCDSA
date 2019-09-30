using System;

class Atcoder81
{
    public static void Main()
    {
        string s = Console.ReadLine();

        if (s.IndexOf("a") >= 0 && s.IndexOf("b") >= 0 && s.IndexOf("c") >= 0)
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }
}