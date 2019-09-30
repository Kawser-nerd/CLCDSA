using System;

public class Hello
{
    public static void Main()
    {
        var sa = Console.ReadLine().Trim();
        var sb = Console.ReadLine().Trim();
        var sc = Console.ReadLine().Trim();
        var pa = 0; var pb = 0; var pc = 0;
        var ba = sa[pa++];
        char ret;
        while (true)
        {
            if (ba == 'a')
                if (pa == sa.Length) { ret = 'A'; break; }
                else ba = sa[pa++];
            else if (ba == 'b')
                if (pb == sb.Length) { ret = 'B'; break; }
                else ba = sb[pb++];
            else if (pc == sc.Length) { ret = 'C'; break; }
            else ba = sc[pc++];
        }
        Console.WriteLine(ret);
    }
}