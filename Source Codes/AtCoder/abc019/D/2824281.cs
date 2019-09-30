using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var maxv = 0;  var maxi = 0;
        for (int i = 2; i <= n; i++)
        {
            Console.WriteLine("? {0} {1}", 1, i);
            var w = int.Parse(Console.ReadLine());
            if (w > maxv) { maxv = w;  maxi = i; }
        }
        var ret = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i != maxi)
            {
                Console.WriteLine("? {0} {1}", maxi, i);
                var w = int.Parse(Console.ReadLine());
                ret = Math.Max(ret, w);
            }
        }
        Console.WriteLine("! {0}",ret);
    }
}