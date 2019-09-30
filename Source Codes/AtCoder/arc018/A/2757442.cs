using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = double.Parse(line[0]);
        var bmi = double.Parse(line[1]);
        var hm = h / 100;
        Console.WriteLine(bmi * hm * hm);
    }
}