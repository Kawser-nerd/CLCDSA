using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Math.Abs(int.Parse(line[0]));
        var b = Math.Abs(int.Parse(line[1]));
        string mes;
        if (a == b) mes = "Draw";
        else if (a < b) mes = "Ant";
        else mes = "Bug";
        Console.WriteLine(mes);
    }
}