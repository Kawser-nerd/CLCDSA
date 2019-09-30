using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var a = s[0] - '0';
        var b = s[1] - '0';
        var c = s[2] - '0';
        var d = s[3] - '0';

        var o = new[] { "+", "-" };
        var op = new[] { 1, -1 };

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if (a + op[i] * b + op[j] * c + op[k] * d == 7)
                    {
                        Console.WriteLine($"{a}{o[i]}{b}{o[j]}{c}{o[k]}{d}=7");
                        return;
                    }
                }
            }
        }
    }
}