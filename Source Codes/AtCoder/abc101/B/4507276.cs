using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var str = Console.ReadLine();
        var num = str.Select(x => int.Parse(x.ToString())).Sum();
        var n = int.Parse(str);
        if (n % num == 0)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}