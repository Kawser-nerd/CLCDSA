using System;

class Program
{
    static void Main(string[] args)
    {
        var abx = Console.ReadLine().Split(' ');
        var a = int.Parse(abx[0]);
        var b = int.Parse(abx[1]);
        var c = int.Parse(abx[2]);

        if (a <= c && c <= a + b)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}