using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string ret;
        if (n == 100) ret = "Perfect";
        else if (n >= 90) ret = "Great";
        else if (n >= 60) ret = "Good";
        else ret = "Bad";
        Console.WriteLine(ret);
    }
}