using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        //?????
        int a = 2025 - int.Parse(Console.ReadLine());
        for (int i = 1; i < 10; i++)
        {
            if (a % i == 0)
            {
                if (a / i < 10) Console.WriteLine(i + " x " + (a / i));
            }
        }

    }
}