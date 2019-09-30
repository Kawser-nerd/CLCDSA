using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        string[] line2 = Console.ReadLine().Trim().Split(' ');
        var x = int.Parse(line2[0]);
        var y = int.Parse(line2[1]);
        string[] line3 = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line3, int.Parse);
        string[] line4 = Console.ReadLine().Trim().Split(' ');
        var b = Array.ConvertAll(line4, int.Parse);
        var aarv = 0; var barv = a[0] + x;
        var ap = 0; var bp = 0;
        var count = 0;
        while (true)
        {
            while (true)
            {
                if (bp == m) goto end;
                if (b[bp] >= barv) { aarv = b[bp] + y; bp++; count++; break; }
                else bp++;
            }
            while (true)
            {
                if (ap == n) goto end;
                if (a[ap] >= aarv) { barv = a[ap] + x; ap++; break; }
                else ap++;
            }
        }
        end:;
        Console.WriteLine(count);
    }
}