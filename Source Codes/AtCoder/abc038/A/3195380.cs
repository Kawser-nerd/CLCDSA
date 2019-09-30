using System;

class Program
{
    static void Main(string[] args)
    {
        var item = Console.ReadLine();
        var str = item.Substring(item.Length - 1, 1)=="T" ? "YES" : "NO";
        Console.WriteLine(str);
    }
}