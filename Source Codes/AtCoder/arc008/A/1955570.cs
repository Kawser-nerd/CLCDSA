using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int money = (n / 10) * 100;
        n = n % 10;
        if (n < 7)
        {
            money += 15 * n;
        }
        else
        {
            money += 100;
        }
        Console.WriteLine(money);
    }
}