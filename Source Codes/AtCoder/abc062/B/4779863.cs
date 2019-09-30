using System;

class Program
{
    static void Main(string[] args)
    {
        var hw = Console.ReadLine().Split(' ');
        var h = int.Parse(hw[0]);
        var w = int.Parse(hw[1]);

        var s = new string[h];
        for (int i = 0; i < h; i++)
        {
            s[i] = Console.ReadLine();
        }

        Console.WriteLine(new string('#', w + 2));
        for (int i = 0; i < h; i++)
        {
            Console.Write("#");
            Console.Write(s[i]);
            Console.WriteLine("#");
        }
        Console.WriteLine(new string('#', w + 2));
    }
}