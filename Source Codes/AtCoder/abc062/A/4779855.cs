using System;

class Program
{
    static void Main(string[] args)
    {
        var a = new[] { 1, 3, 5, 7, 8, 10, 12 };
        var b = new[] { 4, 6, 9, 11 };
        var c = new[] { 2 };

        var s = Console.ReadLine().Split(' ');
        var x = int.Parse(s[0]);
        var y = int.Parse(s[1]);

        if (m1(a, x) && m1(a, y))
        {
            Console.WriteLine("Yes");
        }
        else if (m1(b, x) && m1(b, y))
        {
            Console.WriteLine("Yes");
        }
        else if (m1(c, x) && m1(c, y))
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }

    static bool m1(int[] a, int x)
    {
        for (int i = 0; i < a.Length; i++)
        {
            if (a[i] == x) return true;
        }
        return false;
    }
}