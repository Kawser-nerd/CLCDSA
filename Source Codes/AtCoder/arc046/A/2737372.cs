using System;

public class Hello
{
    public static void Main()
    {
        var a = "912345678";
        var n = int.Parse(Console.ReadLine().Trim());
        var keta = (n + 8) / 9;
        var suji = a[n % 9];
        Console.WriteLine(new string(suji, keta));
    }
}