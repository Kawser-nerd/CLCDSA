using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = double.Parse(line[0]);
        var b = double.Parse(line[1]);
        var c = double.Parse(line[2]);
        var res = calcFt(a, b, c);
        Console.WriteLine(res);
    }
    public static double calcFt(double a, double b, double c)
    {
        var maxt = 200 / a;  var mint = 0d;  var t = 0d;
        for (int i = 0; i < 100; i++)
        {
            t = (maxt + mint) / 2;
            var ft = a * t + b * Math.Sin(Math.PI * c * t) - 100;
            if (ft > 0) maxt = t;
            else if (ft < 0) mint = t;
        }
        return t;
    }
}