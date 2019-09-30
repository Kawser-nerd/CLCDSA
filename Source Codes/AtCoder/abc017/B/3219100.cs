using System;

class Program
{
    static void Main(string[] args)
    {
        var str = Console.ReadLine();
        var result = "";
        str=str.Replace("ch", "");
        str=str.Replace("o", "");
        str=str.Replace("k", "");
        str=str.Replace("u", "");

        result = str == "" ? "YES" : "NO";

        Console.WriteLine(result);
    }
}