using System;

public class Hello
{
    public static void Main()
    {
        var a = new string[] { "A", "B", "C", "D", "E" };
        var s = Console.ReadLine().Trim();
        var sL = s.Length;
        var count = 0;
        foreach (var x in a)
        {
            var res = sL - s.Replace(x, "").Length;
            count += res;
            Console.Write("{0} ", res);
        }
        Console.WriteLine(sL - count);
    }
}