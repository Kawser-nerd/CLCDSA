using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var L = long.Parse(line[1]);
        line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, long.Parse);
        for (int i = 0; i < n-1; i++)
            if (a[i+1] + a[i ] >= L) { Console.WriteLine("Possible"); putAns(n, i); goto end; }
        Console.WriteLine("Impossible");
        end:;
    }
    public static void putAns (int n, int p)
    {
        for (int i = 0; i <= p - 1; i++) Console.WriteLine(i + 1);
        for (int i = n-1; i >= p+2 ; i--) Console.WriteLine(i) ;
        Console.WriteLine(p + 1);
    }
}