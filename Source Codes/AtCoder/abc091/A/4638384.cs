using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().Split(' ');
        var a = int.Parse(s[0]);
        var b = int.Parse(s[1]);
        var c = int.Parse(s[2]);

        if (c <= a + b)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}