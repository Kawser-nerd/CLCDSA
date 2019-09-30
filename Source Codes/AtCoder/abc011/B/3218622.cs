using System;

class Program
{
    static void Main(string[] args)
    {
        var str = Console.ReadLine().ToUpper();
        if(str.Length!=1)
        str = str.Substring(0, 1) + str.Substring(1).ToLower();
        Console.WriteLine(str);
    }
}