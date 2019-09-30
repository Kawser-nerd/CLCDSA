using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var n = Console.ReadLine();
        var head = int.Parse(n[0].ToString());
        var border = head * 100 + head * 10 + head;
        if (int.Parse(n) > border)
        {
            Console.WriteLine(border + 111);
        }
        else
        {
            Console.WriteLine(border);
        }
    }
}