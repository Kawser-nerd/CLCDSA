using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var L = new long[n + 1];
        L[0] = 2;
        L[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            L[i] = L[i - 1] + L[i - 2];
        }
        Console.WriteLine(L[n]);
    }
}