using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n1 = int.Parse(line[0]);
        var n2 = int.Parse(line[1]);
        line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        line = Console.ReadLine().Trim().Split(' ');
        var b = Array.ConvertAll(line, int.Parse);
        Array.Sort(a);
        Array.Sort(b);
        var ab = getAns(a, b, n1, n2);
        Console.WriteLine(ab / (double)(n1 + n2 - ab));
    }
    public static int getAns(int[] a, int[] b, int n1, int n2)
    {
        if (n2 > n1) return getAns(b, a, n2, n1);
        var ret = 0;
        foreach (var x in a)
            if (Array.BinarySearch(b, x) >= 0) ret++;
        return ret;
    }
}