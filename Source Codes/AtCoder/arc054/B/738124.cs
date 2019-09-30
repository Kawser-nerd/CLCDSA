using System;

class Program
{
    static void Main(string[] args)
    {
        var P = double.Parse(Console.ReadLine());

        var left = 0d;
        var right = P;

        for (var i = 0; left < right && i < 150; i++)
        {
            var leftVal = Calc((left * 2 + right) / 3, P);
            var rightVal = Calc((left + right * 2) / 3, P);

            if (leftVal > rightVal)
            {
                left = (left * 2 + right) / 3;
            }
            else
            {
                right = (left + right * 2) / 3;
            }
        }

        Console.WriteLine(Calc((left + right) * 0.5, P).ToString("0.##########"));
    }

    static double Calc(double x, double P)
    {
        return x + P / (Math.Pow(2, x / 1.5));
    }

}