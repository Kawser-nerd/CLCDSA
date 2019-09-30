using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var num1 = Convert.ToInt32(input[0]);
        var num2 = Convert.ToInt32(input[1]);

        var group = new HashSet<int>[3];
        group[0]= new HashSet<int> { 1, 3, 5, 7, 8, 10, 12 };
        group[1] = new HashSet<int> { 4, 6, 9, 11 };
        group[2] = new HashSet<int> { 2 };

        var isSameGroup = false;
        foreach(var val in group)
        {
            if (val.Contains(num1) && val.Contains(num2))
            {
                isSameGroup = true;break;
            }
        }

        var result = isSameGroup ? "Yes" : "No";
        Console.WriteLine(result);
    }
}