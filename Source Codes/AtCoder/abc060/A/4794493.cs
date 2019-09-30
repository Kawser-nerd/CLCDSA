using System;

class Program
{
    static void Main(string[] args)
    {
        var x = Console.ReadLine().Split();
        var a = x[0];
        var b = x[1];
        var c = x[2];

        if (a[a.Length - 1] == b[0] && b[b.Length - 1] == c[0])
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}