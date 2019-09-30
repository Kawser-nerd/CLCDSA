using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine();
        var strs = new string[5];
        for(int i = 0; i < 5; i++)
        {
            strs[i] = input.Substring(i, 1);
        }

        var num = Convert.ToInt32(Console.ReadLine());
        var div = num / 5;
        var mod = num % 5;
        if (mod == 0) Console.WriteLine($"{strs[div - 1]}{strs[4]}");
        else Console.WriteLine($"{strs[div]}{strs[mod-1]}");
        
    }
}