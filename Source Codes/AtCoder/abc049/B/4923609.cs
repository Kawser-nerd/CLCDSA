using System;

class Program
{
    static void Main(string[] args)
    {
        var hw = Console.ReadLine().Split();
        var h = int.Parse(hw[0]);
        var w = int.Parse(hw[1]);

        var c = new string[h];
        for (int i = 0; i < h; i++)
        {
            c[i] = Console.ReadLine();
        }

        for (int i = 0; i < h; i++)
        {
            Console.WriteLine(c[i]);
            Console.WriteLine(c[i]);
        }
    }
}