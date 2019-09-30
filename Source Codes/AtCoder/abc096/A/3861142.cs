using System;
using System.Linq;
class ABC96A
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int m = int.Parse(input[0]);
        int d = int.Parse(input[1]);

        if (m > d)
            m--;


        Console.WriteLine(m);
    }
}