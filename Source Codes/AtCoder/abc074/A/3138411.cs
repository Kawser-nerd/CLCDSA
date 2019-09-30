using System;

class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        int a = int.Parse(Console.ReadLine());
        int ans = n * n - a;

        Console.WriteLine(ans);
    }
}