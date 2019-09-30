using System;

class Program
{
    static void Main(string[] args)
    {
        var abc = Console.ReadLine().Split(' ');
        var n = 100 * int.Parse(abc[0]) + 10 * int.Parse(abc[1]) + int.Parse(abc[2]);

        if (n % 4 == 0)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}