using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var maxname = ""; var maxp = 0; var psum = 0;
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            var s = line[0];
            var p = int.Parse(line[1]);
            psum += p;
            if (p > maxp) { maxname = s; maxp = p; }
        }
        var targ = psum / 2 + 1;
        Console.WriteLine(maxp >= targ ? maxname : "atcoder");
    }
}