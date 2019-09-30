using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;


class Program
{
    static void Main(string[] Args) {
        int metor = Int32.Parse(Console.ReadLine());
        double Result = 0;

        if (metor < 100)
            Result = 0;
        else if (metor <= 5000)
            Result = metor / 100;
        else if (metor <= 30000)
            Result = metor / 1000 + 50;
        else if (metor <= 70000)
            Result = (metor / 1000 - 30) / 5 + 80;
        else
            Result = 89;

        WriteLine(Result.ToString().PadLeft(2, '0'));

        ReadLine();
    }
}