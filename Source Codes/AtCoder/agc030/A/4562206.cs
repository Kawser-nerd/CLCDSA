using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var abc = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var noYam = abc[0];
        var yam = abc[1];
        var poi = abc[2];

        long count = yam;
        if (yam + noYam < poi)
        {
            count += yam + noYam + 1;
        }
        else
        {
            count += poi;
        }

        Console.WriteLine(count);
    }
}