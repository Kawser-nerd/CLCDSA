using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var xyxy = Console.ReadLine().Split().Select(z => int.Parse(z)).ToArray();
        var x = xyxy[2] - xyxy[0];
        var y = xyxy[3] - xyxy[1];
        Console.WriteLine($"{xyxy[2] - y} {xyxy[3] + x} {xyxy[0] - y} {xyxy[1] + x}");
    }
}