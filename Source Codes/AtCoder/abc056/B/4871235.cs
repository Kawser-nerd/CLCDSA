using System;

class Program
{
    static void Main(string[] args)
    {
        var wab = Console.ReadLine().Split();
        var w = int.Parse(wab[0]);
        var a = int.Parse(wab[1]);
        var b = int.Parse(wab[2]);

        if ((a <= b && b <= a + w) ||
            (a - w <= b && b <= a))
        {
            Console.WriteLine(0);
        }
        else
        {
            var ans = Math.Min(
                Math.Abs(a - b + w),
                Math.Abs(a - b - w));

            Console.WriteLine(ans);
        }
    }
}