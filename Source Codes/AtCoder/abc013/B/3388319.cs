using System;
using static System.Console;

class Program
{
    static int Up(int a, int b)
    {
        int result = 0;
        while (a != b)
        {
            a++;
            result++;
            a %= 10;
        }
        return result;
    }

    static int Down(int a, int b)
    {
        int result = 0;
        while (a != b)
        {
            a--;
            result++;
            if (a < 0)
                a = 9;
        }
        return result;
    }

    static void Main()
    {
        int a = int.Parse(ReadLine());
        int b = int.Parse(ReadLine());

        WriteLine(Math.Min(Up(a, b), Down(a, b)));
    }
}