using System;

class Program
{
    static void Main(string[] args)
    {
        var tx = Console.ReadLine().Split(' ');
        var t = double.Parse(tx[0]);
        var x = double.Parse(tx[1]);
        Console.WriteLine(t / x);
    }
}