using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main(string[] args)
    {
        var tem = Console.ReadLine().Split().Select(int.Parse).ToList();
        var a = Math.Abs(tem[1] - tem[0]);
        var count = 0;

        count += a / 10;
        switch (a % 10)
        {
            case 9: 
            case 6: 
            case 4:
            case 2:
                count += 2;
                break;
            case 8:
            case 7:
            case 3:
                count += 3;
                break;
            case 5:
            case 1:
                count += 1;
                break;
            default:
                break;
        }

        Console.WriteLine(count);
    }
}