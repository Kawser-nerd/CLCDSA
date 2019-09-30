using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().ToCharArray();
        var n = int.Parse(Console.ReadLine());
        var nameList = new List<string>();

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                nameList.Add(input[i].ToString() + input[j].ToString());
            }
        }

        Console.WriteLine(nameList[n - 1]);
    }
}