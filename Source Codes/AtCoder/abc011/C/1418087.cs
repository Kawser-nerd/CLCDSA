using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var target = int.Parse(Console.ReadLine());
        var ng1 = int.Parse(Console.ReadLine());
        var ng2 = int.Parse(Console.ReadLine());
        var ng3 = int.Parse(Console.ReadLine());

        ngList = new List<int> { ng1, ng2, ng3 };

        string text = "NO";
        if (ngList.All(n => n != target))
        {
            text = Calculate(target) == 1 ? "YES" : "NO";
        }
        Console.WriteLine(text);
    }

    static List<int> ngList;
    static int count = 0;
    static int Calculate(int num)
    {
        if (count > 100)
        {
            return 0;
        }

        if (num == 0)
        {
            return 1;
        }

        if (num >= 3 && ngList.All(n => n != num - 3))
        {
            count++;
            return Calculate(num - 3);
        }
        else if (num >= 2 && ngList.All(n => n != num - 2))
        {
            count++;
            return Calculate(num - 2);
        }
        else if (ngList.All(n => n != num - 1))
        {
            count++;
            return Calculate(num - 1);
        }
        else
        {
            return 0;
        }
    }
}