using System;

class Program
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        for (int i = 0; i < 2; i++) if (inp[i] == 1) inp[i] = 14;
        if (inp[0] > inp[1]) Console.WriteLine("Alice");
        else if (inp[0] < inp[1]) Console.WriteLine("Bob");
        else Console.WriteLine("Draw");
    }
}