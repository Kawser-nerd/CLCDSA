using System;

class Sample
{
    public static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var i = Console.ReadLine();
        
        int n = int.Parse(i);
        int index = n - 1;
        var result = s[index];

        Console.WriteLine(result);
    }
}