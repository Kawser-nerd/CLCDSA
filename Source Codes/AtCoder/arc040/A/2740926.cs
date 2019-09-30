using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var rc = 0; var bc = 0;
        for (int i = 0; i < n; i++)
        {
            var s = Console.ReadLine().Trim();
            rc += n - s.Replace("R", "").Length;
            bc += n - s.Replace("B", "").Length;
        }
        if (rc == bc) { Console.WriteLine("DRAW"); goto end; }
        Console.WriteLine(rc > bc ? "TAKAHASHI" : "AOKI");
        end:;
    }
}