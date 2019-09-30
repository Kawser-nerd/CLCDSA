using System;

class Program
{
    static void Main(string[] args)
    {
        var xyz = Console.ReadLine().Split(' ');
        var x = int.Parse(xyz[0]);
        var y = int.Parse(xyz[1]);
        var z = int.Parse(xyz[2]);

        var ans = Math.Min(x * y, z);
        Console.WriteLine(ans);
    }
}